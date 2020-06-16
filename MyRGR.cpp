

#include "List.h"

int main()
{

	List<int> lst;
	lst.PushBack(5);
	lst.PushBack(10);
	lst.PushBack(22);
	lst.View(lst);

	lst.PopFront();
	lst.AddID(25, 1);


	lst.View(lst);
	List<int> lst2;
	lst2 = lst2.ReadFile("text.txt", lst2);
	List<int> Q;
	Q = lst.QList(lst, lst2);
	Q.View(Q);


	return 0;
}
