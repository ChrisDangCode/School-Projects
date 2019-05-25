//********************************************************************************
//Chris Dang		CSCI  1125
// Generic Bank Account GUI
//********************************************************************************
package javaProg4;

import java.awt.* ;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.* ;

public class BankAccountGUI {
	
	final int EX_BAL = 25 ;	// example balance and rate to start construction
	final int EX_RATE = 10 ;
	
	final int WIDTH = 230 ;
	final int HEIGHT = 350 ;
	
	// constructs new bank, savings, and checking accounts
	BankAccount bank = new BankAccount(EX_BAL, EX_RATE) ;
	//SavingsAccount save = new SavingsAccount(EX_BAL, EX_RATE) ;
	//CheckingAccount check = new CheckingAccount(EX_BAL, EX_RATE) ;
	
	
	
	
	// Frame of Banking
	JFrame frame = new JFrame("Java Banking") ;
	
	SavingsPanel save = new SavingsPanel() ;
	CheckingPanel check = new CheckingPanel() ;
	
	JTabbedPane tabPane = new JTabbedPane() ;
	

	
	BankAccountGUI() {
		
		// closes account
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.setPreferredSize(new Dimension(WIDTH, HEIGHT));
		
		save.setBackground(Color.cyan) ;
		check.setBackground(Color.pink) ;
//		// sets background
//		JPanel back = new JPanel() ;
//		back.setBackground(Color.gray) ;
//		back.setPreferredSize(new Dimension(WIDTH, HEIGHT));
//		
//		
//		
		
		tabPane.addTab("Savings", save) ;
		tabPane.addTab("Checking", check) ;	
		
//		frame.getContentPane().add(back) ;
		frame.getContentPane().add(tabPane) ;
		frame.pack() ;
		frame.setVisible(true) ;
		
		
	} // end BankAccountGUI
	
}
