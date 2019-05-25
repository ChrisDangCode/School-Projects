//********************************************************************************
//Chris Dang		CSCI  1125
// Generic Bank Account Class
//********************************************************************************

package javaProg4;

public class BankAccount {

	final int MONTHS = 12 ; 
		
	protected int    deposits,   // number of deposits made for the month
			       withdraws ;   // number of withdraws made for the month
	
	protected	double balance,  // balance of account
				   interestRate, // annual interest rate
				   serveCharge ; // monthly service charges
	
	// BankAccount constructor
	// Accepts start balance and starting rate parameters
	public BankAccount(double startBal, double startRate) { 
		deposits = 0 ;
		withdraws = 0 ;
		serveCharge = 0 ;  
		balance = startBal; 
		interestRate = startRate ;			
	} // end constructor 
	
	// function: deposit
	// pre: must include amount that is to be deposited
	// post: adds amount to balance and increments number of deposits for the month
	public void deposit(double depo){
		balance += depo ;
		deposits++ ;
	} // end deposit
	
	// function: withdraw
	// pre: must include amount that is to be withdrawn
	// post: subtracts amount from balance and increments number of withdraws for the month
	public void withdraw(double draw){
		balance -= draw ;
		withdraws++ ;
	} // end withdraw
	
	// function: calcInterest
	// pre: none
	// post: adds interest earned for the month to the account
	public void calcInterest() {
		double monthRate = interestRate / MONTHS ;	// calculates interest rate for month
		double interest = balance * monthRate ;		// calculates interest earned
		balance = balance + interest ;				// adds interest to balance
	} // end calcInterest
	
	// function: monthlyProcess
	// pre: none
	// post: deducts service charge from account, adds interest to account, and zeros out deposits, withdraws, and service charges
	public void monthlyProcess() {
		balance -= serveCharge ;	// deducts service charge from account
		this.calcInterest() ;		// adds interest to account
		deposits = 0 ;				// zeros out deposits, withdraws, and service charges
		withdraws = 0 ;
		serveCharge = 0 ;
	} // end monthlyProcess
	
	
	
} // end class bankAccount