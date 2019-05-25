//********************************************************************************
//Chris Dang		CSCI  1125
// Checking Account Panel 
//********************************************************************************
package javaProg4;

import java.awt.* ;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import javax.swing.* ;


public class CheckingPanel extends JPanel{
	
	DecimalFormat fmt = new DecimalFormat("0.##") ;			// formats output for display
	
	
	private JTextField depositFld , withdrawFld, rateFld ;
	private JButton depNow, withNow, modRate, procNow ;
	
	
	final int EX_BAL = 25 ;				// example balance and rate to start construction
	final int EX_RATE = 10 ;
	
	CheckingAccount check = new CheckingAccount(EX_BAL, EX_RATE) ;

	double beginBal = check.balance ;	// begin balance holds balance for start of month
	
	// labels that display stats for the month
	JLabel monthlyInfo = new JLabel("Current Month's Info:") ;
	JLabel beginBalLbl = new JLabel(   "Beginning Balance: " + beginBal) ;
	JLabel monthDpt =    new JLabel("    Current Deposits: " + check.deposits) ;
	JLabel monthDrw =    new JLabel("   Current Withdraws: " + check.withdraws) ;
	JLabel yearRate =    new JLabel("Annual Interest Rate: " + check.interestRate) ;
	JLabel monthChg =    new JLabel("     Service Charges: " + check.serveCharge) ;
	JLabel endBalLbl =   new JLabel("      Ending Balance: " + check.balance) ;
	

	
	public CheckingPanel() {
		
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
		add(monthChg) ;
		add(endBalLbl) ;
		
		// adds text fields and buttons to panel
		add(depositFld) ;
		add(depNow) ;
		depNow.addActionListener(new depoListen()) ;
		
		add(withdrawFld) ;
		add(withNow) ;
		withNow.addActionListener(new withListen()) ;
		
		add(rateFld) ;
		add(modRate) ;
		modRate.addActionListener(new rateListen());
		
		add(procNow) ;
		procNow.addActionListener(new procListen());
		
	} // end CheckingPanel()
	
	// depoListen
	// deposits amount from text field to the balance
	private class depoListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
			try {
			
			String temp = depositFld.getText() ;										// get text
			double depoAmt ;
			
			depoAmt = Double.parseDouble(temp) ;										// convert text to double
			
			check.deposit(depoAmt) ;													// deposit amount
			
			monthDpt.setText("    Current Deposits: " + check.deposits) ;				// updates number of deposits
			endBalLbl.setText("      Ending Balance: " + fmt.format(check.balance)) ;	// updates balance
			
			// resets text fields
			depositFld.setText("Deposit Amount");				
			withdrawFld.setText("Withdraw Amount");
			rateFld.setText("Interest Rate");
			
			} // end try
			
				catch(NumberFormatException exception) 	// catches in case alphabet characters are entered into text field
				{
					System.out.println("Error -- can only accept double values") ;
				}
		
		} // end actionPerformed
	
	} // end depoListen
	
	// withListen
	// withdraws amount from text field from the balance
	private class withListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
			try {
			
			String temp = withdrawFld.getText() ;										// get text
			double drawAmt ;

			drawAmt = Double.parseDouble(temp) ;										// convert text to double

			check.withdraw(drawAmt) ;													// withdraw amount
			
			monthDrw.setText("   Current Withdraws: " + check.withdraws) ;				// updates number of withdraws
			
			endBalLbl.setText("      Ending Balance: " + fmt.format(check.balance)) ;	// updates balance
			
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
	
	// rateListen
	// updates annual rate from text field
	private class rateListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
		
			try {
			
			String temp = rateFld.getText() ;										// get text
			double rateAmt ;

			rateAmt = Double.parseDouble(temp) ;									// convert text to double

			check.interestRate = rateAmt ;											// rate amount
			
			yearRate.setText("Annual Interest Rate: " + check.interestRate);		// updates interest rate
			
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
	
	// rateListen
	// processes account for the month
	private class procListen implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {

			check.monthlyProcess() ;											// processes account
			
			beginBal = check.balance ;											// updates beginning balance
			
			
			// updates stats
			beginBalLbl.setText(   "Beginning Balance: " + fmt.format(beginBal)) ;
			monthDpt.setText("    Current Deposits: " + check.deposits) ;			
			monthDrw.setText("   Current Withdraws: " + check.withdraws) ;

			// resets text fields
			monthChg.setText("     Service Charges: " + check.serveCharge);
			endBalLbl.setText("      Ending Balance: " + fmt.format(check.balance)) ;	
			
		
		} // end actionPerformed
	
	} // end rateListen
	

} // end CheckingPanel

