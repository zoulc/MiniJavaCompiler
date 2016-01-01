class Test {
    public static void main(String[] s) {
        Templt<int> t;
	Base b;
        int r;
        t = new Templt<int>();
	b = new Base();
	r = t.setVal(2);
        System.out.println(t.getVal());
    }
}

class Templt<T> extends Base {
    T a;
    public T getVal() {
	Invoker f;
	f=(T x,T y)->{return x+y;};
	T c;
	c=f(a,a);
        return c;
    }
    public int setVal(T v) {
        a = v;
        return 0;
    }
}

class Base {
    int b;
    public int init() {
        b = 0;
	return 0;
    }
}
