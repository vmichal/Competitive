
// BigInteger (non)standard header
// Vojt�ch Michal, 21.3.2018; 

//28.3.2018 p�id�n k�d umo��uj�c� benchmarkov�n� metod
//31.3.2018 dokon�en a debugnut	algoritmus na odmoc�ov�n�

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector> 
#include <string>
#include <iostream>
			  
class BigInteger {

private:
	std::vector<uint32_t> cislice_;
	int8_t sign_;

	std::vector<uint8_t> convert(int8_t base) const;
	inline void checkInternalState();

public:		

	/////////////////////////////
	// Konstruktory, assignment
	/////////////////////////////
	BigInteger() : sign_(0) {}
	BigInteger(int64_t cislo);
	BigInteger(const std::string& str, int8_t radix = 10);
	BigInteger(const std::vector<uint32_t>& vec, int8_t sign);
	BigInteger(std::vector<uint32_t>&& vec, int8_t sign);

	BigInteger(const BigInteger& rhs) = default;
	BigInteger& operator=(const BigInteger& rhs) = default;
	BigInteger(BigInteger&& rhs) = default;
	BigInteger& operator=(BigInteger&& rhs) = default;


	/////////////////////////////
	// P��stup k jednotliv�m ��sl�m
	/////////////////////////////
	uint32_t& operator[](size_t index);
	const uint32_t& operator[](size_t index) const;
	uint32_t& at(size_t index);
	const uint32_t& at(size_t index) const;	   


	/////////////////////////////
	// Size, bitCount
	/////////////////////////////
	///<summary>
	///Vr�t� po�et 32bitov�ch integer�, kter� tvo�� ��slo (d�lka vectoru ��sel).
	///</summary>
	size_t size() const { return cislice_.size(); }
	size_t bitCount() const;
	explicit operator bool() const;

	/////////////////////////////
	// Bitov� operace
	/////////////////////////////
	void setBit(uint32_t index);
	void clearBit(uint32_t index);
	void toggleBit(uint32_t index);
	bool isBitSet(uint32_t index) const;	

	/////////////////////////////
	// Bitov� logika
	/////////////////////////////
	BigInteger operator&(const BigInteger& rhs) const;
	BigInteger operator|(const BigInteger& rhs) const;
	BigInteger& operator&=(const BigInteger& rhs);
	BigInteger& operator|=(const BigInteger& rhs);


	/////////////////////////////
	// Bit shift
	/////////////////////////////
	BigInteger operator<<(uint32_t pocet) const;
	BigInteger operator>>(uint32_t pocet) const;
	BigInteger& operator<<=(uint32_t pocet);
	BigInteger& operator>>=(uint32_t pocet);

	/////////////////////////////
	// Aritmetick� oper�tory
	/////////////////////////////
	BigInteger operator+(const BigInteger &druhy) const;
	BigInteger operator-(const BigInteger &druhy) const;
	BigInteger operator*(const BigInteger &druhy) const;
	BigInteger operator/(const BigInteger &druhy) const;
	BigInteger operator%(const BigInteger &druhy) const;

	/////////////////////////////
	// Aritmetick� oper�tory a assignment
	/////////////////////////////
	BigInteger& operator+=(const BigInteger &druhy);
	BigInteger& operator-=(const BigInteger &druhy);
	BigInteger& operator*=(const BigInteger &druhy);
	BigInteger& operator/=(const BigInteger &druhy);
	BigInteger& operator%=(const BigInteger &druhy);


	/////////////////////////////
	// Inkrementace, dekrementace
	/////////////////////////////
	BigInteger operator++(int);
	BigInteger operator--(int);	 
	BigInteger& operator++();
	BigInteger& operator--(); 
							   
	/////////////////////////////
	// Mocn�n�
	/////////////////////////////
	BigInteger pow(uint32_t mocnina) const;
	BigInteger sqrt() const;

	/////////////////////////////
	// Is metody (kladne, zero, liche)
	/////////////////////////////
	bool isZero() const { return !sign_; }
	bool isKladne() const { return sign_ == 1; }
	bool isZaporne() const { return sign_ == -1; }
	bool isSude() const { return (cislice_[0] ^ 1) & 1; }
	bool isLiche() const { return cislice_[0] & 1; }
									   	

	/////////////////////////////
	// Comparison, equality
	/////////////////////////////
	bool operator<(const BigInteger& druhy) const;
	bool operator>(const BigInteger& druhy) const;
	bool operator==(const BigInteger& druhy) const;
	bool operator!=(const BigInteger& druhy) const;
	bool operator>=(const BigInteger& druhy) const;
	bool operator<=(const BigInteger& druhy) const;	   
								 

	/////////////////////////////
	// Aritmetick� metody, absolutn� hodnoty
	/////////////////////////////
	static BigInteger add(const BigInteger& a, const BigInteger& b);
	static BigInteger sub(const BigInteger& a, const BigInteger& b);
	static BigInteger multiply(const BigInteger& a, const BigInteger& b);
	static BigInteger divide(const BigInteger& delenec_param, const BigInteger& delitel_param, BigInteger* zbytek = nullptr);
	static BigInteger zbytek(const BigInteger& delenec_param, const BigInteger& delitel_param);
	static BigInteger abs(const BigInteger& cislo);
	static BigInteger zapornaAbs(const BigInteger& cislo);
	static BigInteger opacnaHodnota(const BigInteger& cislo);  	

	/////////////////////////////
	// Convert funkce, print
	/////////////////////////////
	std::string printDec() const;
	std::string printHex() const;
	std::string printBin() const;
	std::string print(int8_t base) const;
	std::string printExp(uint32_t presnost = 0) const;	  
	int64_t valueOf() const;

	/////////////////////////////
	// Input/Output
	/////////////////////////////
	friend std::ostream& operator<<(std::ostream& stream, const BigInteger& a);
	friend std::istream& operator>>(std::istream& stream, BigInteger& a);
};
#endif //BIGINTEGER_H ^^  