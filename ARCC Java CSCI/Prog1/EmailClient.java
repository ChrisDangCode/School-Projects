import java.awt.* ;
import java.awt.event.* ;

import javax.swing.*;


public class EmailClient extends JPanel {

		final int fieldSize = 10 ;
		
		
		//labels to describe text field
		JLabel toLabel = new JLabel("To:") ;
		JLabel cCLabel = new	JLabel("CC:") ;
		JLabel bCCLabel = new JLabel("BCC:") ;
		JLabel subjectLabel = new JLabel("Subject:") ;
		JLabel messageLabel = new JLabel("Email Message:") ;
		
		//text fields
		JTextField toField = new JTextField(fieldSize) ;
		JTextField cCField = new JTextField(fieldSize) ;
		JTextField bCCField = new JTextField(fieldSize) ;
		JTextField subjectField = new JTextField(fieldSize) ;
		JTextField messageBodyField = new JTextField(fieldSize) ;

		public EmailClient()
		{
			add(toLabel) ;
			add(toField) ;
			add(cCLabel) ;
			add(cCField) ;
			add(bCCLabel) ;
			add(bCCField) ;
			add(subjectLabel) ;
			add(subjectField) ;
			add(messageLabel) ;
			add(messageBodyField) ;
			
			JButton send = new JButton("Send") ;
			send.addActionListener(new PushSend()) ;
			
			add(send) ;
			
		}
		

	private class PushSend implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
		//displays email
		
		String printTo, printCC, printBCC, printSubject, printBody;
		
			printTo = toField.getText() ;
			printCC = cCField.getText() ;
			printBCC = bCCField.getText() ;
			printSubject = subjectField.getText() ;
			printBody = messageBodyField.getText() ;
		
			System.out.println("     To: " + printTo) ;
			System.out.println("\n     CC: " + printCC) ;
			System.out.println("\n    BCC: " + printBCC) ;
			System.out.println("\nSubject: " + printSubject) ;
			System.out.println("\nMessage: " + printBody) ;
		
		}
	}
	
}


