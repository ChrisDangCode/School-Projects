import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class EmailClientDriver {
	
	public static void main(String[] args) 
	{
		//creates frame of email client
		JFrame frame = new JFrame("Email") ;
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;

		

		frame.getContentPane().add(new EmailClient()) ;
		frame.pack() ;
		frame.setVisible(true);
		
	}
}
