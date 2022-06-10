#ifndef NODE_HPP
#define NODE_HPP

class Node
{
	private:
		int data;
		Node* next;
	public:
		Node(int data);
		Node();
		~Node();
		Node& operator=(const Node& obj);
		void SetNext(Node* next);
		int GetValue()const;
		Node* GetNext()const;

};

#endif
