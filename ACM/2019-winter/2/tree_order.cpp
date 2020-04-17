#include <iostream>
#include <vector>

int find(int* array, int value) {
	for (int i = 0; ; ++i)
		if (array[i] == value)
			return i;
}

bool are_same_tree(int* preorder, int* postorder, int* inorder, int length) {
	if (length == 0)
		return true;
	int const parent = *preorder;
	if (*(postorder + length - 1) != parent)
		return false;
	//terminating case: if we have only single element, we have reached the leaf and we should get the same vertex
	if (length == 1) 
		return *postorder == parent && *inorder == parent;

	int left_length = find(inorder, parent);
	int right_length = length - left_length - 1;

	return are_same_tree(preorder + 1, postorder, inorder, left_length)
		&& are_same_tree(preorder + (length - right_length), postorder + left_length, 
			inorder + left_length + 1, right_length);
}

int main(int, char**) {

	int V;
	std::cin >> V;
	std::vector<int> pre(V), post(V), in(V);
	auto ref = { &pre, &post, &in };
	for (auto* vector : ref)
		for (int i = 0; i < V; ++i)
			std::cin >> vector->at(i);

	std::cout << (are_same_tree(pre.data(), post.data(), in.data(), V) ? "yes\n" : "no\n");
}