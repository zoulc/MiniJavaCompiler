class Test{
    public static void main(String[] a){
	int a ;
	Tester b ;
        Reader c ; 
	b = new Tester2();
	a = b.set();
	System.out.println(a);
	c = new Reader() ; 
	a = c.read(b);
	System.out.println(a);
	a = b.work();
	System.out.println(a);
    }
}

interface Container{
    public int set();
    public int work();
}

class Tester implements Container {
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

class Tester2 extends Tester implements Container{
    public int work() {
	    a=a+2;
        return a;
    }
}

class Reader {
    int a ;
    public int read( Container s )
    {
        a = s.work();
        return a ;
    }
}
