class Test{
	public static void main(String[] a){
}

class Pair
{
	public Invoker mk_pair(int a,int b)
	{
		return (int w)->{
			int c;
			if(w<1)c=a;
				else c=b;
			return c;
		};
	}

	public Invoker append()
	{

	}

	public int fir(Invoker a)
	{
		return a(0);
	}
	
	public int sec(Invoker a)
	{
		return a(1);
	}

}
