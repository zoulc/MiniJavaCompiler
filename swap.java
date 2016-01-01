class Test {
    public static void main(String[] s) {
        int r;
        Integer inta;
        Integer intb;
        Func fun;
        inta = new Integer();
        intb = new Integer();
        fun = new Func();
	r = inta.setval(3);
        r = intb.setval(4);        
	r = fun.swap(inta, intb);
        System.out.println(inta.getval());
        System.out.println(intb.getval());
    }
}

class Integer {
    int val;
    public int getval() {
        return val;
    }
    public int setval(int _val) {
        val = _val;
        return 0;
    }
}

class Func {
    public int swap(Integer a, Integer b) {
        Integer t;
        t = new Integer();
        t.val = a.val;
	a.val = b.val;
	b.val = t.val;
	return 0;
    }
}
