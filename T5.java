class Test{
	public static void main(String[] a){
		Tester x;
		int y;
//		Invoker z;
//		Invoker u;
		x = new Tester();
//		y = x.set(3);
//		z = x.xc();
		y = x.work2();
//		y = u(1,z);
//		y=x.work(x);
//		y=z(1,x);
		System.out.println(y);
    }
}


class Tester
{
	int c;

	public int set(int x)
	{
		c=x;
		return 0;
	}	

	public int get()
	{
		return c;
	}

	public Invoker xc()
	{
		Invoker f;
		f=(int x)->{return x+c;};
		return f;
	}

//	public int work(Tester y)
//	{
//		return y.get();
//	}

	public int work2()
	{
		Invoker f;
		Invoker g;
		int q;
		g=(int a)->{return a+3;};
		f=(int x,Invoker h)->{return h(x);};
		q=f(1,g);
		return q;
	}

}

