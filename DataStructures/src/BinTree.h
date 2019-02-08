#pragma once

namespace DSP
{
	template <typename T>
	class BinTree
	{
	public:
		struct Node;

		BinTree() : root(nullptr) {}

		BinTree(const BinTree<T>& other) : root(nullptr)
		{
			copyTree(other);
		}

		virtual ~BinTree()
		{
			deleteRecursively(root);
		}

		BinTree<T>& operator=(const BinTree<T>& other)
		{
			if (this != &other)
			{
				deleteRecursively(root);
				copyTree(other);
			}
			return *this;
		}

		BinTree(const T& other, const BinTree<T>& left, const BinTree<T>& right)
			: root(nullptr)
		{
			root = new Node{ other, nullptr, nullptr };
			copyRecursively(root->left, left.root);
			copyRecursively(root->right, right.root);
		}

		bool empty() const
		{
			return root == nullptr;
		}

		T getRoot() const
		{
			return root->data;
		}

		void insert(const T& x)
		{
			add(root, x);
		}

		void remove(const T& x)
		{
			root = remove(root, x);
		}

		BinTree<T> leftTree() const
		{
			BinTree<T> res;
			copyRecursively(res->root, root->left);
			return res;
		}

		BinTree<T> rightTree() const
		{
			BinTree<T> res;
			copyRecursively(res->root, root->right);
			return res;
		}

	private:
		struct Node
		{
			T data;
			Node *left, *right;
		};

		Node* root;

		void copyTree(const BinTree<T>& other)
		{
			copyRecursively(root, other.root);
		}

		void copyRecursively(Node*& to, Node* const & from) const
		{
			to = nullptr;

			if (from == nullptr)
				return;

			to = new Node{ from->data, nullptr, nullptr };
			copyRecursively(to->left, from->left);
			copyRecursively(to->right, from->right);
		}

		void deleteRecursively(Node*& curr) const
		{
			if (curr == nullptr)
				return;

			deleteRecursively(curr->left);
			deleteRecursively(curr->right);
			delete curr;
			curr = nullptr;
		}

		void add(Node*& root, const T& elem)
		{
			if (!root)
			{
				root = new Node{ elem, nullptr, nullptr };
			}
			else
			{
				if (root->data < elem)
					add(root->right, elem);
				else
					add(root->left, elem);
			}
		}

		T removeMinElem(Node* r oot)
		{
			Node* cur = root;
			Node* prev = root;
			while (cur->left != nullptr)
			{
				prev = cur;
				cur = cur->left;
			}
			T minElem = cur->data;
			prev->left = nullptr;
			delete cur;
			return minElem;
		}

		Node* remove(Node* node, const T& elem)
		{
			if (!node) return node;
			if (node->data == elem && !node->left) {
				Node* right = node->right;
				delete node;
				return right;
			}
			if (node->data == elem && !node->right) {
				Node* left = node->left;
				delete node;
				return left;
			}
			if (node->data == elem)
			{
				node->data = removeMinElem(node->right);
				return node;
			}

			if (node->data < elem)
			{
				node->right = remove(node->right, elem);
			}
			else
			{
				node->left = remove(node->left, elem);
			}
			return node;
		}
	};
}