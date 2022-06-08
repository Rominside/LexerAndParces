#include "LinkedList.h"

LinkedList::LinkedList(std::string name)
{
    this->name = name;
	this->first = nullptr;
	this->last = nullptr;
}

bool LinkedList::is_empty()
{
	return first == nullptr;
}

void LinkedList::push_back(int _val)
{
    Node* p = new Node(_val);
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}

Node* LinkedList::find(int _val)
{
    Node* p = first;
    while (p && p->val != _val) p = p->next;
    return (p && p->val == _val) ? p : nullptr;
}

void LinkedList::remove_first()
{
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
}

void LinkedList::remove_last()
{
    if (is_empty()) return;
    if (first == last) {
        remove_first();
        return;
    }
    Node* p = first;
    while (p->next != last) p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
}

void LinkedList::remove(int _val)
{
    if (is_empty()) return;
    if (first->val == _val) {
        remove_first();
        return;
    }
    else if (last->val == _val) {
        remove_last();
        return;
    }
    Node* slow = first;
    Node* fast = first->next;
    while (fast && fast->val != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        //cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}

int LinkedList::size()
{
    Node* size = first;
    int size_int = 0;
    while (size != last) { size->next; size_int++; }
    return size_int;
}
