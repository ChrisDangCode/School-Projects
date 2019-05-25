//********************************************************************************
// Chris Dang		CSCI  1125
// Saving Account Panel 
//********************************************************************************
package javaProg4;

import java.awt.* ;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.* ;
import java.text.* ;

public class SavingsPanel extends JPanel{
	
	
	DecimalFormat fmt = new DecimalFormat("0.##") ;			// formats output for display
	
	
	private JTextField depositFld , withdrawFld, rateFld ;
	private JButton depNow, withNow, modRate, procNow ;
	
	final int EX_BAL = 25 ;				// example balance and rate to start construction
	final int EX_RATE = 10 ;
	
	SavingsAccount save = new SavingsAccount(EX_BAL, EX_RATE) ;
	
	
	double beginBal = save.balance ;
	
	// labels that display stats for the month
	JLabel monthlyInfo = new JLabel("Current Month's Info:") ;
	JLabel beginBalLbl = new JLabel(   "Beginning Balance: " + beginBal) ;
	JLabel monthDpt =    new JLabel("    Current Deposits: " + save.deposits) ;
	JLabel monthDrw =    new JLabel("   Current Withdraws: " + save.withdraws) ;
	JLabel yearRate =    new JLabel("Annual Interest Rate: " + save.interestRate) ;
	JLabel monthAct =    new JLabel("      Account Active: " + save.active) ;
	JLabel endBalLbl =   new JLabel("      Ending Balance: " + save.balance) ;
	


	public SavingsPanel() {
		
		// buttons
		depNow = new JButton("Deposit") ;
		withNow = new JButton("Withdraw") ;
		modRate = new JButton("Change Rate") ;
		procNow = new JButton("Process Account Now") ;
	
		// text fields
		depositFld = new JTextField("Deposit Amount") ;
		withdrawFld = new JTextField("Withdraw Amount") ;
		rateFld = new JTextField("Interest Rate") ;
	
		
		// adds stats to panel
		add(monthlyInfo) ;
		add(beginBalLbl) ;
		add(monthDpt) ;
		add(monthDrw) ;
		add(yearRate) ;
		add(monthAct) ;
		add(endBalLbl) ;
		
		// adds text fields and buttons
		add(depositFld) ;
		add(depNow) ;
//		depositFld.addActionListener(new clickText()) ;
		depNow.addActionListener(new depoListen()) ;
		
		add(withdrawFld) ;
		add(withNow) ;
		withNow.addActionListener(new withListen()) ;	
		
		add(rateFld) ;
		add(modRate) ;
		modRate.addActionListener(new rateListen());
		
		add(procNow) ;
		procNow.addActionListener(new procListen());
		
		
	} // end SavingsPanel

	// depoListen
	// deposits amount from text field to the balance
	private class depoListen implements ActionListener {
	
		public void actionPerformed(ActionEvent event) {
		
			
			try{
			
			
			String temp = depositFld.getText() ;										// get text
			double depoAmt ;
			
			depoAmt = Double.parseDouble(temp) ;										// convert text to double
			
			save.deposit(depoAmt) ;														// deposit amount
			

			monthDpt.setText("    Current Deposits: " + save.deposits) ;
			monthAct.setText("      Account Active: " + save.active);
			endBalLbl.setText("      Ending Balance: " + fmt.format(save.balance)) ;	
			
			// resets text fields
			depositFld.setText("Deposit Amount");
			withdrawFld.setText("Withdraw Amount");
			rateFld.setText("Interest Rate");
		
			} // end try
			
			catch(NumberFormatException exception) 
				{
					System.out.println("Error -- can only accept double values") ;
				}
			
		} // end actionPerformed
	
	} // end depoListen
	
	
	private class withListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
			try {
			
			String temp = withdrawFld.getText() ;
			double drawAmt ;

			drawAmt = Double.parseDouble(temp) ;

			save.withdraw(drawAmt) ;
			
			monthDrw.setText("   Current Withdraws: " + save.withdraws) ;
			monthAct.setText("      Account Active: " + save.active);
			endBalLbl.setText("      Ending Balance: " + fmt.format(save.balance)) ;	
			
			// resets text fields
			depositFld.setText("Deposit Amount");
			withdrawFld.setText("Withdraw Amount");
			rateFld.setText("Interest Rate");
		

		
		} // end try
		
		catch(NumberFormatException exception) 
			{
				System.out.println("Error -- can only accept double values") ;
			}
			
		} // end actionPerformed
	} // end withListen
	
	
	private class rateListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
			try {
			
			String temp = rateFld.getText() ;
			double rateAmt ;

			rateAmt = Double.parseDouble(temp) ;

			save.interestRate = rateAmt ;
			
			yearRate.setText("Annual Interest Rate: " + save.interestRate);
			
			// resets text fields
			depositFld.setText("Deposit Amount");
			withdrawFld.setText("Withdraw Amount");
			rateFld.setText("Interest Rate");
			
			} // end try 
			
			catch(NumberFormatException exception) 
				{
					System.out.println("Error -- can only accept double values") ;
				}
			
			
		
		} // end actionPerformed
	
	} // end rateListen
	
	
	private class procListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {

			save.monthlyProcess() ;
			
			beginBal = save.balance ;
			
			// updates stats
			beginBalLbl.setText(   "Beginning Balance: " + fmt.format(beginBal)) ;
			monthDpt.setText("    Current Deposits: " + save.deposits) ;			
			monthDrw.setText("   Current Withdraws: " + save.withdraws) ;
			monthAct.setText("      Account Active: " + save.active);
			endBalLbl.setText("      Ending Balance: " + fmt.format(save.balance)) ;	
			
		
		} // end actionPerformed
	
	} // end rateListen
	


} // end SavingsPanel
