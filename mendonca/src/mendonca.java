



public class mendonca {
	
	//static int wait_miliseconds  = 10*60*60*100;
	static int wait_miliseconds  = 1;
	
	public static void main(String[] args) {		
		try{
			MendoncaThread oMendonca = new MendoncaThread();
			oMendonca.args = args;
			java.lang.Thread th = new Thread(oMendonca);
			th.start();
//			//java.lang.Thread.sleep(wait_miliseconds);
//			th.join(wait_miliseconds);
//			int i = 1*1000;
//			System.err.println(Integer.toString(i));
			
		}
		catch(Exception ex)
		{
			System.err.println("Unhandled exception: " + ex.getMessage() );
		}
	}
	


}
