class Test{
	public static void main(String[] a){
    	Invoker x;
		Invoker ix;
		int y;
		x=(int c,int d)->{
			Invoker e;
			e=(int f,int g)->{
				return c*f+d*g;
			};
			return e;
		};
		ix=x(1,2);
		y=ix(1,2);
		System.out.println(y);

		Invoker za;
		Invoker zb;
		Invoker merge;
		Invoker z;
		merge=(Invoker c,Invoker d)->{return (int e)->{return c(d(e));};};
		za=(int u)->{return 2*u;};
		zb=(int u)->{return u+1;};
		z=merge(za,zb);
		y=z(5);
		System.out.println(y);
		z=merge(zb,za);
		y=z(5);
		System.out.println(y);
	}
}


