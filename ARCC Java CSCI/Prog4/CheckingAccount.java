//********************************************************************************
//Chris Dang		CSCI  1125
// Checking Account Class
//********************************************************************************
package javaProg4;

import java.awt.* ;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.* ;


public class CheckingAccount extends BankAccount{
	
	final int CHARGE = 15 ;					// service CHARGE for overdraw
	final int FEE = 5 ;						// monthly FEE
	final double FEE_RATE = 0.10 ;			// CHARGEs 10 cents 
	
	
	// CheckingAccount constructor
	// Accepts start balance and starting rate parameters
	public CheckingAccount(double startBal, double startRate) {
		super(startBal, startRate) ;
	} // end constructor
	
	// function: withdraw
	// pre: must include amount that is to be withdrawn
	// post: CHARGEs if account if overdrawn and denies withdrawal, otherwise withdraws
	public void withdraw(double draw){
		
		double newSum = balance - draw ;	// calculates how much account if withdrawn
		
		if (newSum < 0) 					// if negative,
			balance -= CHARGE ;				// apply CHARGE and deny withdraw
			
		else
			super.withdraw(draw) ;			// else, withdraw
		
	} // end withdraw

	// function: monthlyProcess
	// pre: none
	// post: CHARGEs if too many withdraws, processes account
	public void monthlyProcess() {
		
		serveCharge = FEE + (FEE_RATE * withdraws) ;	// calculates FEE total and applies to monthly FEE
		super.monthlyProcess() ; 					// processes account
		
	} // end monthlyProcess
	
	
	
	
} // end CheckingAccount


