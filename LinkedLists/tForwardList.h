#pragma once
#include <cassert>
template<typename T>
class tList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
		Node * prev;                // pointer to node before this node
	};

	int nodeCount;
	void push_empty();

	Node * head;                    // pointer to head of linked list
	Node * tail;                    // pointer to tail of linked list

public:
	tList(); // initializes head to null
	~tList(); // delete all nodes upon destruction
	tList(const tList& other); // copy-constructor--------------------------------------------
	tList& operator=(const tList &rhs); // copy-assignment------------------------------------

	void push_front(const T& val); // adds element to front (i.e. head)
	void pop_front(); // removes element from front
	void push_back(const T& val); // adds element to back (i.e. before back)
	void pop_back(); // removes element from back

	T& front(); // returns the element at the head
	const T& front() const; // returns the element at the head (const)
	T& back(); // returns the element at the tail
	const T& back() const; // returns the element at the tail (const)

	void remove(const T& val); // removes all elements equal to the given value---------------------------------------
	bool empty() const; // Returns true if there are no elements
	void clear(); // Destroys every single node in the linked list
	void resize(size_t newSize); // Resizes the linked list to contain the given number of elements-----------------------------------

	class iterator
	{
		Node * cur;                                 // current node being operated upon
	public:
		iterator(); // initializes an empty iterator pointing to null
		iterator(Node * startNode);  // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const; // returns a reference to the element pointed to by the current node

		iterator operator++(int); // post-increment (returns an iterator as it was before it was incremented)
		iterator operator--(int); // post-increment (returns an iterator as it was before it was decremented)
		iterator& operator++(); // pre-increment (returns a reference to this iterator after it is incremented)
		iterator& operator--(); // pre-increment (returns a reference to this iterator after it is decremented)
	};

	iterator begin(); // returns an iterator pointing to the first element-----------------------------------
	const iterator begin() const; // returns a const iterator pointing to the first element
	iterator end(); // returns an iterator pointing to one past the last element-------------------------------
	const iterator end() const; // returns a const iterator pointing to one past the last element
};

template<typename T>
inline tList<T>::iterator::iterator() // initializes an empty iterator pointing to null
{
	iterator *iter = new iterator();
	iter = nullptr;
}

template<typename T>
inline tList<T>::iterator::iterator(Node * startNode)  // initializes an iterator pointing to the given node
{
	iterator *iter = new iterator();
	iter = startNode;
}

template<typename T>
inline bool tList<T>::iterator::operator==(const iterator & rhs) const // returns true if the iterator points to the same node
{
	if (rhs.cur == cur)
		return true;
	else
		return false;
}

template<typename T>
inline bool tList<T>::iterator::operator!=(const iterator & rhs) const // returns false if the iterator does not point to the same node
{
	if (rhs.cur != cur)
		return true;
	else
		return false;
}

template<typename T>
inline T & tList<T>::iterator::operator*() const // returns a reference to the element pointed to by the current node----------------------
{
	return cur->data;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::iterator::operator++(int) // post-increment (returns an iterator as it was before it was incremented)
{
	iterator iter;
	if (cur != nullptr)
	{
		iter.cur = cur;
		cur = cur->next;
	}
	return iter;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::iterator::operator--(int) // post-increment (returns an iterator as it was before it was decremented)
{
	iterator iter;
	if (cur != nullptr)
	{
		iter.cur = cur;
		cur = cur->prev;
	}
	return iter;
}

template<typename T>
typename inline tList<T>::iterator & tList<T>::iterator::operator++() // pre-increment (returns a reference to this iterator after it is incremented)
{
	if (cur != nullptr)
		cur = cur->next;
	return *this;
}

template<typename T>
typename inline tList<T>::iterator & tList<T>::iterator::operator--() // pre-increment (returns a reference to this iterator after it is decremented)
{
	if (cur != nullptr)
		cur = cur->prev;
	return *this;
}

template<typename T>
inline void tList<T>::push_empty()
{
	Node* tmp = new Node();
	if (tail == nullptr)
	{
		tmp->next = nullptr;
		tmp->prev = nullptr;
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	nodeCount++;
}

template<typename T>
inline tList<T>::tList() // initializes head to null
{
	nodeCount = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline tList<T>::~tList() // delete all nodes upon destruction
{
}

template<typename T>
inline tList<T>::tList(const tList & other)// copy-constructor--------------------------------------------
{
	if (head == nullptr)
	{
		head = new Node();
	}

	nodeCount = other.nodeCount;
	Node* current = head;
	Node* otherNode = other.head;

	for (int i = 0; i < nodeCount; i++)
	{
		if (otherNode != nullptr)
		{
			*current = *otherNode;
			tail = current;
			if (otherNode->next != nullptr)
			{
				current->next = new Node();
				*current->next = *otherNode->next;
			}
			current = current->next;
			otherNode = otherNode->next;
		}
	}
}
template<typename T>
inline tList<T> & tList<T>::operator=(const tList & rhs) // copy-assignment------------------------------------
{
	clear();
	if (head == nullptr)
	{
		head = new Node();
	}

	nodeCount = rhs.nodeCount;
	Node* current = head;
	Node* otherNode = rhs.head;

	for (int i = 0; i < nodeCount; i++)
	{
		if (otherNode != nullptr)
		{
			*current = *otherNode;
			tail = current;
			if (otherNode->next != nullptr)
			{
				current->next = new Node();
			}
			current = current->next;
			otherNode = otherNode->next;
		}
	}
}

//----------------------------------------------------------------------------------------

template<typename T>
inline void tList<T>::push_front(const T & val) // adds element to front (i.e. head)
{
	Node* tmp = new Node();
	tmp->data = val;
	if (head == nullptr)
	{
		tmp->next = nullptr;
		tmp->prev = nullptr;
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	nodeCount++;
}

template<typename T>
inline void tList<T>::pop_front() // removes element from front
{
	if (head != nullptr)
	{
		Node* tmp;
		tmp = head;
		head = head->next;
		delete tmp;
		if (head == nullptr)
			tail = nullptr;
		else
			head->prev = nullptr;
		nodeCount--;
	}
}

template<typename T>
inline void tList<T>::push_back(const T & val) // adds element to back (i.e. before back)
{
	Node* tmp = new Node();
	tmp->data = val;
	if (tail == nullptr)
	{
		tmp->next = nullptr;
		tmp->prev = nullptr;
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	nodeCount++;
}

template<typename T>
inline void tList<T>::pop_back() // removes element from back
{
	if (tail != nullptr)
	{
		Node* tmp;
		tmp = tail;
		tail = tail->prev;
		delete tmp;
		if (tail == nullptr)
			head = nullptr;
		else
			tail->next = nullptr;
		nodeCount--;
	}
}

template<typename T>
inline T & tList<T>::front() // returns the element at the head
{
	assert(head != nullptr && "Error: The List is empty.");
	return head->data;
}

template<typename T>
inline const T & tList<T>::front() const // returns the element at the head (const)
{
	assert(head != nullptr && "Error: The List is empty.");
	return head->data;
}

template<typename T>
inline T & tList<T>::back() // returns the element at the tail
{
	assert(head != nullptr && "Error: The List is empty.");
	return tail->data;
}

template<typename T>
inline const T & tList<T>::back() const // returns the element at the tail (const)
{
	assert(head != nullptr && "Error: The List is empty.");
	return tail->data;
}

template<typename T>
inline void tList<T>::remove(const T & val) // removes all elements equal to the given value---------------------------------------------------------
{
	Node* firstNode = head;

	for (int i = 0; i < nodeCount; i++)
	{
		if (firstNode != nullptr)
		{
			if (firstNode->data == val)
			{
				Node* tmp = firstNode->next;
				if (firstNode == head)
					head = firstNode->next;

				if (firstNode == tail)
					tail = firstNode->prev;

				firstNode->prev->next = firstNode->next;
				firstNode->next->prev = firstNode->prev;

				delete firstNode;
				firstNode = tmp;
			}
			else
			{
				firstNode = firstNode->next;
			}
		}
	}
}

template<typename T>
inline bool tList<T>::empty() const // Returns true if there are no elements
{
	if (head == nullptr && tail == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void tList<T>::clear() // Destroys every single node in the linked list
{
	while (head != nullptr)
		pop_front();
}

template<typename T>
inline void tList<T>::resize(size_t newSize) // Resizes the linked list to contain the given number of elements
{
	int a = nodeCount - newSize;

	if (nodeCount >= newSize)
		for (int i = 0; i < a; i++)
		{
			pop_back();
		}
	else
		for (int o = 0; o > a; o--)
		{
			push_empty();
		}
}

template<typename T>
typename inline tList<T>::iterator tList<T>::begin()// returns an iterator pointing to the first element-----------------------------------
{
	iterator *iter;
	if (iter == head)
		return iter;
	else
		return nullptr;
}

template<typename T>
typename inline const tList<T>::iterator tList<T>::begin() const // returns a const iterator pointing to the first element
{
	iterator *iter;
	if (iter == head)
		return iter;
	else
		return nullptr;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::end() // returns an iterator pointing to one past the last element-------------------------------
{
	iterator *iter;
	if (iter == tail)
		return iter;
	else
		return nullptr;
}

template<typename T>
typename inline const tList<T>::iterator tList<T>::end() const // returns a const iterator pointing to one past the last element
{
	iterator *iter;
	if (iter == tail)
		return iter;
	else
		return nullptr;
}
