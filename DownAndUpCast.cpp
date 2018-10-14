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