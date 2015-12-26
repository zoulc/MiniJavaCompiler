class Test{
    public static void main(String[] a){
	int a ;
	Tester b ; 
	Reader c ; 
        b = new Tester();
	a = b.set();
	a = b.work();
	System.out.println(a);
	a = b.work();
	System.out.println(a);
    }
}

class Tester{
    int a ; 
    public int set()
    {
	a=0;
	return 0;
    }

    public int work() {
	a=a+1;
        return a; 
    }
}

class Tseter2 extends Tester {
    int b ; 
    public int work() {
	b=b+2;
        return b; 
    }
}
