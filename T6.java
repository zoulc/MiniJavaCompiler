class Test{
	public static void main(String[] a){
		Tester x;
		int y;
		Invoker z;
		//Invoker u;
		x = new Tester();
		y = x.set(3);
		//z = x.xc();
		//u = x.work();
		//y = u(1,z);
		z=x.work(x);
//		y=z(1,x);
		y=z(x);
		System.out.println(y);
		y=x.set(1);
		y=z(x);
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

	public Invoker work(Tester b)
	{
		return 
		(Tester a)->{
			int x;
			int y;
			x=a.get();
			y=b.get();
			return x+y+c;
		};
	}

}

