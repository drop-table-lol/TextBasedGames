/*A quick (misguided) lesson on casting. Instead of casting, or using pointers
to point to the parent class portion of the child class in memory, I just used
a template function to use whatever class was passed. This might be casting,
but it is implicit and isn't useful from learning as the programmer's perspective.*/
/*TODO: A better example would be to use pointers, or references, and pass by ref or address
(instead of by value) and show that we can downcast (upcast?) from a child to a parent, but not
vice versa, and that to use the child function, we should use virtual functions to override the parent
functions.*/

class parent {
	private:
		int parent_int_;
	public:
		ChangeInt(int x) {
			parent_int_ += x;
		}
};

class child : parent {
	private:
		int child_int_;
	public:
		ChangeInt(int x) {
			child_int_ -= x;
		}
};

void reglfunc(parent p1, parent p2) {
	p1.ChangeInt(10);
	p2.ChangeInt(10);
}

void tempfunc(<T> t1, <T> t2) {
	t1.ChangeInt(10);
	t2.ChangeInt(10);
}

int main() {
	parent P1;
	parent P2;
	child c1;
	child c2;
	reglfunc(P1, P2);
	tempfunc(c1, c2);
	return 0;
	};