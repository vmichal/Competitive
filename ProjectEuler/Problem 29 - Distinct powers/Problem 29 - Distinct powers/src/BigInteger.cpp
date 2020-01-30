#include "BigInteger.h"	  									 
#include <exception>
#include <ctype.h>
#include <stdint.h>
#include <chrono>

//#define BIGINTEGER_DEBUG  

#ifdef BIGINTEGER_DEBUG
class Timer {
	std::chrono::time_point<std::chrono::steady_clock> start;
	static uint32_t next_id;
	uint32_t id;
	const char *ptr_;
public:
	static bool verbose;
	Timer(const char* ptr) {
		if (verbose) {
			id = next_id++;
			ptr_ = ptr;
			std::cout << "Benchmark id " << id << " in " << ptr << " started" << std::endl;
			start = std::chrono::high_resolution_clock::now();
		}
	}

	~Timer() {
		if (verbose) {
			std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;
			std::cout << "Benchmark " << id << " of function " << ptr_ << " ended in " << duration.count() * 1000 << "ms" << std::endl;
		}
	}
};
uint32_t Timer::next_id = 0;
bool Timer::verbose = false;
#endif

BigInteger::BigInteger(int64_t cislo)
	: sign_(cislo > 0 ? 1 : cislo < 0 ? -1 : 0) {
	uint64_t c = cislo < 0 ? -cislo : cislo;
	while (c) {
		cislice_.push_back(c & UINT_MAX);
		c >>= 32;
	}
	checkInternalState();
}

BigInteger::BigInteger(const std::string& str, int8_t radix) : sign_(1) {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && *iterator == '0')
		iterator++;
	if (str.end() == iterator) {
		sign_ = 0;
		return;
	}
	if (*iterator == '-') {
		sign_ = -1;
		iterator++;
	}
	for (; iterator != str.end(); iterator++) {
		if (*iterator == '\'' || *iterator == '_')
			continue;
		uint64_t carry = isdigit(*iterator) ? *iterator - '0' : 10 + islower(*iterator) ? *iterator - 'a' : *iterator - 'A';
		if (carry < 0 || carry >= radix)
			throw std::invalid_argument("neplatná èíslice v zápisu èísla.");
		for (uint32_t &i : cislice_) {
			carry += uint64_t(i) * radix;
			i = carry & 0xffff'ffff;
			carry >>= 32;
		}
		while (carry) {
			cislice_.push_back(carry & 0xffff'ffff);
			carry >>= 32;
		}
	}
	checkInternalState();
}

BigInteger::BigInteger(const std::vector<uint32_t>& vec, int8_t sign)
	: sign_(sign),
	cislice_(vec) {
	checkInternalState();
}

BigInteger::BigInteger(std::vector<uint32_t>&& vec, int8_t sign)
	: sign_(sign),
	cislice_(std::forward<std::vector<uint32_t>>(vec)) {
	checkInternalState();
}

uint32_t& BigInteger::operator[](size_t index) {
	return at(index);
}

const uint32_t& BigInteger::operator[](size_t index) const {
	return at(index);
}

uint32_t& BigInteger::at(size_t index) {
	if (index >= 0 && index<cislice_.size())
		return cislice_.at(index);
	throw std::out_of_range("Pokus o pøístup k neplatnému indexu èísla.");
}

const uint32_t& BigInteger::at(size_t index) const {
	if (index >= 0 && index<cislice_.size())
		return cislice_.at(index);
	throw std::out_of_range("Pokus o pøístup k neplatnému indexu èísla.");
}

///<summary>
///Odstarní z vectoru všechny pøebyteèné nuly a v pøípadì potøeby upraví znaménko
///</summary>
void BigInteger::checkInternalState() {
	while (!cislice_.empty() && !cislice_.back())
		cislice_.pop_back();
	if (cislice_.empty())
		sign_ = 0;
	else if (!sign_)
		throw std::exception("vnitøní stav objektu byl narušen");
}

size_t BigInteger::bitCount() const {
	if (isZero())
		return 0;
	size_t count = (size() - 1) << 5;
	for (uint32_t mostSig = cislice_.back(); mostSig; count++, mostSig >>= 1);
	return count;
}

BigInteger::operator bool() const {
	return sign_;
}

void BigInteger::setBit(uint32_t index) {
	if (isZero())
		sign_ = 1;
	uint32_t indexCisla = index >> 5;
	if (indexCisla >= size())
		cislice_.resize(indexCisla + 1);
	cislice_[indexCisla] |= 1 << (index & 0x1f);
}

void BigInteger::clearBit(uint32_t index) {
	if (index < bitCount()) {
		cislice_[index >> 5] &= ~(1 << (index & 0x1f));
		checkInternalState();
	}
}

void BigInteger::toggleBit(uint32_t index) {
	if (index >= bitCount())
		return setBit(index);
	cislice_[index >> 5] ^= 1 << (index & 0x1f);
	checkInternalState();
}

bool BigInteger::isBitSet(uint32_t index) const {
	if (index >= bitCount())
		return false;
	return cislice_[index >> 5] & 1 << (index & 0x1f);
}

BigInteger BigInteger::operator&(const BigInteger& rhs) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	const std::vector<uint32_t>& delsi = this->size() < rhs.size() ? rhs.cislice_ : this->cislice_,
		&kratsi = this->size() < rhs.size() ? this->cislice_ : rhs.cislice_;
	std::vector<uint32_t> vysledek(kratsi);
	auto d = delsi.begin();
	auto v = vysledek.begin();
	while (v != vysledek.end())
		*v++ &= *d++;
	return BigInteger(std::move(vysledek), sign_);
}

BigInteger BigInteger::operator|(const BigInteger& rhs) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	const std::vector<uint32_t>& delsi = this->size() < rhs.size() ? rhs.cislice_ : this->cislice_,
		&kratsi = this->size() < rhs.size() ? this->cislice_ : rhs.cislice_;
	std::vector<uint32_t> vysledek(delsi);
	auto k = kratsi.begin();
	auto v = vysledek.begin();
	while (k != kratsi.end())
		*v++ |= *k++;
	return BigInteger(std::move(vysledek), sign_);
}

BigInteger& BigInteger::operator&=(const BigInteger& rhs) {
	return *new(this) BigInteger(*this & rhs);
}

BigInteger& BigInteger::operator|=(const BigInteger& rhs) {
	return *new(this) BigInteger(*this | rhs);
}

BigInteger BigInteger::operator+(const BigInteger& druhy) const {
	return add(*this, druhy);
}

BigInteger BigInteger::operator-(const BigInteger& druhy) const {
	return sub(*this, druhy);
}

BigInteger BigInteger::operator*(const BigInteger& druhy) const {
	return multiply(*this, druhy);
}

BigInteger BigInteger::operator/(const BigInteger& druhy) const {
	return divide(*this, druhy);
}

BigInteger BigInteger::operator%(const BigInteger& druhy) const {
	return zbytek(*this, druhy);
}

BigInteger BigInteger::operator++(int) {
	BigInteger result(*this);
	++*this;
	return result;
}

BigInteger BigInteger::operator--(int) {
	BigInteger result(*this);
	--*this;
	return result;
}

BigInteger& BigInteger::operator++() {
	return *this += 1;
}

BigInteger& BigInteger::operator--() {
	return *this -= 1;
}

BigInteger& BigInteger::operator+=(const BigInteger& druhy) {
	if (druhy.isZero())
		return *this;
	return *new(this) BigInteger(*this + druhy);
}

BigInteger& BigInteger::operator-=(const BigInteger& druhy) {
	if (druhy.isZero())
		return *this;
	return *new(this) BigInteger(*this - druhy);
}

BigInteger& BigInteger::operator*=(const BigInteger& druhy) {
	return *new(this) BigInteger(*this * druhy);
}

BigInteger& BigInteger::operator/=(const BigInteger& druhy) {
	if (druhy == 1)
		return *this;
	return *new(this) BigInteger(*this / druhy);
}

BigInteger& BigInteger::operator%=(const BigInteger& druhy) {
	divide(BigInteger(*this), druhy, this);
	return *this;
}

BigInteger BigInteger::operator<<(uint32_t pocet) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (pocet < 0)
		throw std::invalid_argument("Velikost posunutí musí být vìtší než nula");
	if (!sign_)
		return *this;
	std::vector<uint32_t> novy(pocet / 32, 0); 	//dodá na konec èísla tolik nul, kolikrát by se posouvalo o 32 bitù
	pocet &= 0x1f; //vezme posledních 5 bitù èísla (totéž jako modulo 32)
	uint64_t carry = 0;
	for (const uint32_t &iterator : cislice_) {
		carry |= uint64_t(iterator) << pocet;
		novy.push_back(carry & 0xFFFF'FFFF);
		carry >>= 32;
	}
	if (carry)
		novy.push_back(carry & 0xFFFF'FFFF);
	return BigInteger(std::move(novy), sign_);
}

BigInteger BigInteger::operator>>(uint32_t pocet) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (pocet < 0)
		throw std::invalid_argument("Velikost posunutí musí být vìtší než nula");
	if (!sign_)
		return *this;
	auto iterator = cislice_.begin() + (pocet >> 5 < cislice_.size() ? pocet >> 5 : cislice_.size()); //posune iterator o (pocet/32) bitù nebo na konec vectoru
	if (iterator == cislice_.end()) //bylo-li posunutí vìtší, poté vracíme nulu
		return BigInteger();
	pocet &= 0x1f; //totéž co modulo 32
	if (!pocet)
		return BigInteger(std::vector<uint32_t>(iterator, cislice_.end()), sign_);
	std::vector<uint32_t> novy;
	uint64_t carry = *iterator++ >> pocet;
	while (iterator != cislice_.end()) {
		carry |= uint64_t(*iterator++) << 32 - pocet;
		novy.push_back(carry & 0xFFFF'FFFF);
		carry >>= 32;
	}
	if (carry)
		novy.push_back(carry & 0xFFFF'FFFF);
	return BigInteger(std::move(novy), sign_);
}

BigInteger& BigInteger::operator<<=(uint32_t pocet) {
	return *new(this) BigInteger(*this << pocet);
}

BigInteger& BigInteger::operator>>=(uint32_t pocet) {
	return *new(this) BigInteger(*this >> pocet);
}

BigInteger BigInteger::pow(uint32_t mocnina) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	switch (mocnina) {
	case 0:
		return 1;
	case 1:
		return *this;
	case 2:
		return *this**this;
	}
	mocnina -= 2;
	BigInteger vysledek = *this**this;

	while (mocnina--)
		vysledek *= *this;
	return vysledek;
}

///<summary>
/// Vrátí nejvìtší celé èíslo menší nebo rovno odmocninì
///<summary>
BigInteger BigInteger::sqrt() const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (isZero())
		return 0;
	/*if (bitCount() < 64) {
	return BigInteger(std::sqrt(valueOf()));
	}*/
	int8_t shift = (bitCount() & 0x1f) - 2;
	if (shift & 1)
		shift++;
	auto iterator = cislice_.rbegin();
	BigInteger zbytek = *iterator >> shift & 0x3, odmocnina = std::sqrtl(zbytek.valueOf());
	zbytek -= odmocnina.pow(2);
	for (; iterator != cislice_.rend(); iterator++) {
		while ((shift-=2) >= 0) {
			zbytek = (zbytek << 2) + (*iterator >> shift & 0x3);
			uint8_t cislice = zbytek >= (odmocnina << 2 | 1);
			if (cislice)
				zbytek -= (odmocnina << 2) | 1;
			odmocnina = odmocnina << 1 | cislice;
		}
		shift = 32;
	}
	return odmocnina;
}

bool BigInteger::operator<(const BigInteger& druhy) const {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (sign_ != druhy.sign_)
		return sign_ < druhy.sign_;
	if (bitCount() != druhy.bitCount())
		return sign_ == -1 ^ bitCount() < druhy.bitCount(); //vrátí true pro (sign_ = 1 && this<druhy) nebo (sign_ = -1 && this>druhy
	for (auto a = cislice_.rbegin(), b = druhy.cislice_.rbegin(); a != cislice_.rend(); a++, b++)
		if (*a != *b)
			return (sign_ == 1) ^ (*a > *b);
	return false;
}

bool BigInteger::operator>(const BigInteger& druhy) const {
	return druhy < *this;
}

bool BigInteger::operator==(const BigInteger & druhy) const {
	if (sign_ == druhy.sign_ && cislice_.size() == druhy.cislice_.size()) {
		for (auto a = cislice_.begin(), b = druhy.cislice_.begin(); a != cislice_.end(); a++, b++)
			if (*a != *b)
				return false;
		return true;
	}
	return false;
}

bool BigInteger::operator!=(const BigInteger& druhy) const {
	return !(*this == druhy);
}

bool BigInteger::operator<=(const BigInteger& druhy) const {
	return !(*this > druhy);
}

bool BigInteger::operator>=(const BigInteger& druhy) const {
	return !(*this < druhy);
}

BigInteger BigInteger::add(const BigInteger& lhs, const BigInteger& rhs) {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (lhs.isZero())
		return rhs;
	if (rhs.isZero())
		return lhs;
	if (lhs.isKladne() && rhs.isKladne()) {
		uint64_t carry = 0;
		const std::vector<uint32_t>& kratsi = lhs.size() < rhs.size() ? lhs.cislice_ : rhs.cislice_;
		std::vector<uint32_t> vysledek(lhs.size() < rhs.size() ? rhs.cislice_ : lhs.cislice_);
		auto k = kratsi.begin();
		auto v = vysledek.begin();

		while (k != kratsi.end()) {
			carry += uint64_t(*k++) + *v;
			*v++ = carry & 0xFFFF'FFFF;
			carry >>= 32;
		}
		while (v != vysledek.end() && carry) {
			carry += *v;
			*v++ = carry & 0xFFFF'FFFF;
			carry >>= 32;
		}
		if (carry)
			vysledek.push_back(carry);
		return BigInteger(std::move(vysledek), 1);
	}
	if (lhs.isZaporne() && rhs.isZaporne())
		return zapornaAbs(abs(lhs) + abs(rhs));

	if (lhs.isZaporne() && rhs.isKladne())
		return rhs - abs(lhs);

	if (lhs.isKladne() && rhs.isZaporne())
		return lhs - abs(rhs);
}

BigInteger BigInteger::sub(const BigInteger& mensenec, const BigInteger& mensitel) {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (mensitel.isZero())
		return mensenec;
	if (mensenec.isZero())
		return opacnaHodnota(mensitel);
	if (mensenec.isKladne() && mensitel.isKladne()) {
		if (mensenec >= mensitel) {
			std::vector<uint32_t> vysledek(mensenec.cislice_);
			auto delsi = vysledek.begin();
			auto kratsi = mensitel.cislice_.begin();
			int64_t carry = 0;
			while (kratsi != mensitel.cislice_.end()) {
				carry += int64_t(*delsi) - *kratsi++;
				if (carry >= 0) {
					*delsi++ = carry;
					carry = 0;
				}
				else {
					*delsi++ = carry + 0x1'0000'0000;
					carry = -1;
				}
			}
			while (carry) {
				carry += int64_t(*delsi);
				if (carry >= 0) {
					*delsi++ = carry;
					carry = 0;
				}
				else {
					*delsi++ = carry + 0xFFFF'FFFF;
					carry = -1;
				}
			}
			return BigInteger(std::move(vysledek), 1);
		}
		return zapornaAbs(mensitel - mensenec);
	}
	if (mensenec.isKladne() && mensitel.isZaporne())
		return mensenec + abs(mensitel);

	if (mensenec.isZaporne() && mensitel.isKladne())
		return zapornaAbs(abs(mensenec) + mensitel);

	if (mensenec.isZaporne() && mensitel.isZaporne())
		return opacnaHodnota(abs(mensenec) - abs(mensitel));
}

BigInteger BigInteger::multiply(const BigInteger& a, const BigInteger& b) {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (a.isZero() || b.isZero())
		return BigInteger();
	std::vector<uint32_t> novy(a.cislice_.size() + b.cislice_.size() + 1);
	const std::vector<uint32_t>& delsi = a.size() < b.size() ? b.cislice_ : a.cislice_,
		&kratsi = a.size() < b.size() ? a.cislice_ : b.cislice_;
	uint64_t carry, offset = 0;
	for (size_t i = 0; i < kratsi.size(); i++) {
		carry = 0;
		for (size_t j = 0; j < delsi.size(); j++) {
			carry += uint64_t(kratsi[i]) * delsi[j] + novy[i + j];
			novy[i + j] = carry & 0xffff'ffff;
			carry >>= 32;
		}
		if (carry)
			novy[i + delsi.size()] = carry & 0xffff'ffff;
	}
	return BigInteger(std::move(novy), a.sign_ == b.sign_ ? 1 : -1);
}

BigInteger BigInteger::divide(const BigInteger& delenec_param, const BigInteger& delitel_param, BigInteger* zbytek) {
#ifdef BIGINTEGER_DEBUG
	Timer timer(__func__);
#endif
	if (delitel_param.isZero())
		throw std::exception("Není možné dìlit nulou");
	if (delitel_param == 1)
		return delenec_param;
	if (delitel_param == -1)
		return opacnaHodnota(delenec_param);
	bool trebaMazatZbytek = false;
	if (!zbytek) {
		trebaMazatZbytek = true;
		zbytek = new BigInteger(abs(delenec_param));
	}
	else
		new(zbytek) BigInteger(abs(delenec_param));
	BigInteger podil;
	BigInteger* delitel = new BigInteger(1);
	uint32_t mocnina = 0;
	std::vector<BigInteger> mocniny;
	mocniny.reserve(delitel_param.bitCount() / delitel_param.bitCount());
	while (*zbytek >= *delitel) {
		mocniny.push_back(*delitel);
		mocnina++;
		*delitel *= abs(delitel_param);
	}
	delete delitel;
	if (mocniny.empty()) {
		if (trebaMazatZbytek)
			delete zbytek;
		else
			zbytek->sign_ = delenec_param.sign_ == delitel_param.sign_ ? delenec_param.sign_ : -delenec_param.sign_;
		return BigInteger();
	}
	delitel = &mocniny.back();
	while (--mocnina) {
		uint32_t miraZanoreni = 0;
		while (*zbytek >= *delitel) {
			miraZanoreni++;
			*delitel <<= 1;
		}
		while (miraZanoreni--) {
			*delitel >>= 1;
			if (*zbytek >= *delitel) {
				*zbytek -= *delitel;
				podil += mocniny[mocnina - 1] << miraZanoreni;
			}
		}
		delitel--;
	}
	podil.sign_ = zbytek->sign_ = delitel_param.sign_ == delenec_param.sign_ ? delenec_param.sign_ : -delenec_param.sign_;
	if (trebaMazatZbytek)
		delete zbytek;
	return podil;
}

BigInteger BigInteger::zbytek(const BigInteger& delenec, const BigInteger& delitel) {
	BigInteger zbytek;
	divide(delenec, delitel, &zbytek);
	return zbytek;
}

BigInteger BigInteger::abs(const BigInteger& cislo) {
	if (!cislo.sign_)
		return cislo;
	BigInteger novy(cislo);
	novy.sign_ = 1;
	return novy;
}

BigInteger BigInteger::zapornaAbs(const BigInteger& cislo) {
	if (cislo.sign_ == -1)
		return cislo;
	BigInteger novy = cislo;
	novy.sign_ = -1;
	return novy;
}

BigInteger BigInteger::opacnaHodnota(const BigInteger& cislo) {
	if (cislo.sign_ == -1)
		return zapornaAbs(cislo);
	return abs(cislo);
}

std::string BigInteger::printDec() const {
	return print(10);
}

std::string BigInteger::printHex() const {
	std::string str;
	if (!sign_) {
		str.push_back('0');
		return str;
	}
	if (sign_ == -1)
		str.push_back('-');
	str.push_back('0');
	str.push_back('x');
	uint32_t prvni = *cislice_.rbegin();
	bool jsouCisla = false;
	for (int i = 7; i >= 0; i--) {
		int8_t nibble = prvni >> (4 * i) & 0xf;
		if (nibble || jsouCisla) {
			str.push_back(nibble < 10 ? nibble + '0' : nibble + 'A' - 10);
			jsouCisla = true;
		}
		if (jsouCisla && i % 2 == 0)
			str.push_back('_');
	}
	for (auto iterator = cislice_.rbegin() + 1; iterator != cislice_.rend(); iterator++) {
		uint32_t c = *iterator;
		for (int i = 7; i >= 0; i--) {
			int8_t nibble = c >> (4 * i) & 0xf;
			str.push_back(nibble < 10 ? nibble + '0' : nibble + 'A' - 10);
			if (i % 2 == 0)
				str.push_back('_');
		}
	}
	str.pop_back();
	return str;
}

std::string BigInteger::printBin() const {
	std::string str;
	if (!sign_) {
		str.push_back('0');
		return str;
	}
	if (sign_ == -1)
		str.push_back('-');
	str.push_back('0');
	str.push_back('b');
	uint32_t prvni = *cislice_.rbegin();
	bool jsouCisla = false;
	for (int i = 31; i >= 0; i--) {
		int8_t bit = prvni >> i & 1;
		if (jsouCisla)
			str.push_back(bit + '0');
		else if (bit) {
			str.push_back(bit + '0');
			jsouCisla = true;
		}
		if (jsouCisla && i % 4 == 0)
			str.push_back('_');
	}
	for (auto iterator = cislice_.rbegin() + 1; iterator != cislice_.rend(); iterator++) {
		uint32_t c = *iterator;
		for (int i = 31; i >= 0; i--) {
			int8_t bit = c >> i & 1;
			str.push_back(bit + '0');
			if (i % 4 == 0)
				str.push_back('_');
		}
	}
	str.pop_back();
	return str;
}

std::string BigInteger::print(int8_t base) const {
	if (base == 2)
		return printBin();
	if (base == 16)
		return printHex();
	std::vector<uint8_t> cisla(convert(base));
	std::string str;
	if (sign_ == -1)
		str.push_back('-');
	for (std::vector<uint8_t>::const_iterator i = cisla.begin(); i != cisla.end(); i++) {
		str.push_back(*i + '0');
		if ((cisla.end() - i - 1) % 3 == 0)
			str.push_back('.');
	}
	str.pop_back();
	return str;
}

std::string BigInteger::printExp(uint32_t presnost) const {
	if (sign_ == 0)
		return std::string("0");
	std::vector<uint8_t> cisla(convert(10));
	std::string str;
	std::vector<uint8_t>::const_iterator iterator = cisla.begin();
	if (sign_ == -1)
		str.push_back('-');
	str.push_back(*iterator++ + '0');
	str.push_back(',');
	int8_t rad = 0;
	if (presnost) {
		while (iterator != cisla.end() && presnost--) {
			str.push_back(*iterator++ + '0');
			if (++rad % 3 == 0) {
				str.push_back('.');
			}
		}
		if (iterator != cisla.end())
			if (*iterator > 4)
				str.back()++;
	}
	else
		while (iterator != cisla.end()) {
			str.push_back(*iterator++ + '0');
			if (++rad % 3 == 0) {
				str.push_back('.');
			}
		}
	str.append(" x 10^");
	str.append(std::to_string(cisla.size() - 1));
	return str;
}

///<summary>
///Vrátí posledních 63 bitù èísla jako int64_t hodnotu
///</summary>
int64_t BigInteger::valueOf() const {
	if (!sign_)
		return 0;
	if (cislice_.size() == 1)
		return cislice_.at(0) * sign_;
	int64_t result = (uint64_t(cislice_.at(1)) << 32 | cislice_.at(0)) & 0x7fff'ffff'ffff'ffff;
	if (sign_ == -1)
		result = ~result + 1;
	return result;
}

///<summary>
///Vrátí èíslo jako vector bajtù reprezentujících èíslice jeho zápisu v soustavì o daném základu
///<summary>
std::vector<uint8_t> BigInteger::convert(int8_t base) const {
	if (!sign_)
		return std::vector<uint8_t> { 0 };
	std::vector<uint8_t> novy;
	for (auto iterator = cislice_.rbegin(); iterator != cislice_.rend(); iterator++) {
		uint64_t carry = *iterator;
		for (uint8_t & i : novy) {
			carry += uint64_t(i) << 32;
			i = carry % base;
			carry /= base;
		}
		while (carry) {
			novy.push_back(carry % base);
			carry /= base;
		}
	}
	std::reverse(novy.begin(), novy.end());
	return novy;
}

std::ostream & operator<<(std::ostream & stream, const BigInteger& a) {
	if (stream.flags() & std::ostream::hex)
		return stream << a.printHex();
	if (stream.flags() & std::ostream::binary)
		return stream << a.printBin();
	return stream << a.printDec();
}

std::istream& operator>>(std::istream& stream, BigInteger& a) {
	std::string str;
	char znak;
	while (isalpha(znak = stream.get()) || isdigit(znak)) {
		str.push_back(znak);
	}
	new(&a) BigInteger(std::move(str));
	return stream;
}