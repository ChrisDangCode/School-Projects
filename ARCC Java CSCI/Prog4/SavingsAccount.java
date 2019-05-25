//********************************************************************************
// Chris Dang		CSCI  1125
// Checking Account Class
//********************************************************************************
package javaProg4;


public class SavingsAccount extends BankAccount {
		
	final int MINIMUM = 25 ;		// MINIMUM amount for active to stay active is $25
	final int CHARGE = 1 ;
	final int MAX_DRAW = 4 ;
	protected boolean active ;

	// SavingsAccount constructor
	// Accepts start balance and starting rate parameters
	public SavingsAccount(double startBal, double startRate) {
		
		super(startBal, startRate) ;	
		
		if (startBal >= MINIMUM)
			active = true ;
		else 
			active = false ;
	} // end SavingsAccount constructor
	
	// function: deposit
	// pre: must include amount that is to be deposited
	// post: if new balance brings total to > MINIMUM, reactivates account, and deposits money
	public void deposit(double depo){
		
		double newSum = depo + balance ;		// calculate new sum
		
		if (!active && newSum > MINIMUM)  		// reactivates account if
			active = true ;						// account is not active and 
												// new sum is > MINIMUM	
		
		super.deposit(depo);						// deposits with parent class deposit 
		
	} // end deposit
	
	// function: withdraw
	// pre: must include amount that is to be withdrawn
	// post: if active, subtracts amount from balance and if balance falls below MINIMUM, deactivates account
	public void withdraw(double draw){
		
		if (active) {							// no withdrawal is made if not active
			
			super.withdraw(draw);				// withdraws with parent class withdraw
			
			if (balance < MINIMUM)				// checks if balance falls below MINIMUM
				active = false ;				// deactivates account if balance < MINIMUM
			
		} // end if
		
	} // end withdraw
	
	
	// function: monthlyProcess
	// pre: none
	// post: CHARGEs if too many withdraws, processes account, and disables if amount falls below MINIMUM
	public void monthlyProcess() {
		
		if (withdraws > MAX_DRAW) {				// if more than MAX_DRAW number of withdraws
			int deduct = CHARGE * (withdraws - MAX_DRAW) ;	
			balance -= deduct ;					// deduct a dollar for each withdraw above MAX_DRAW
		} // end if
			
		super.monthlyProcess();
		
		if (balance < MINIMUM)					// checks if balance falls below MINIMUM
			active = false ;					// deactivates account if balance < MINIMUM
		
	} // end monthlyProcess
	
	
} // end SavingsAccount




