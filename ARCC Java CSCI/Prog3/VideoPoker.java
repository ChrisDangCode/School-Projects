//******************************************************************************
// Chris Dang			CSCI Java 1125
// VideoPoker.Java
//******************************************************************************
import java.awt.* ;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.* ;

public class VideoPoker {
	
	// initial values
	private int javaDollar = 10 ;
	private int javaEarned = 0 ;
	private boolean replaceBool1 = false ;
	private boolean replaceBool2 = false ;
	private boolean replaceBool3 = false ;
	private boolean replaceBool4 = false ;
	private boolean replaceBool5 = false ;
	
		// creates deck for game
		Deck pokerDeck = new Deck() ;
		
		// creates hand for game
		Hand pokerHand = new Hand() ;
		
		// Dimensions for Poker game display
		final int WIDTH = 450 ;
		final int HEIGHT = 410 ;
		final int INFO_WIDTH = 100 ;
		final int INFO_HEIGHT = 220 ;
		final int PAY_WIDTH = 125 ;
		final int PAY_HEIGHT = 30 ;
		final int CARD_WIDTH = 400 ;
		final int CARD_HEIGHT = 110 ;
		
		// Payout values for winning hands
		final int PAIR = 1 ;
		final int TWO_PAIR = 2 ;
		final int THREE_KIND = 3 ;
		final int STRAIGHT = 4 ;
		final int FLUSH = 5 ;
		final int FULL_HOUSE = 6 ;
		final int FOUR_KIND = 25 ;
		final int STRAIGHT_FLUSH = 50 ;
		final int ROYAL_FLUSH = 250 ;
		
		// Frame of video poker
		JFrame frame = new JFrame("Video Poker") ;
		

		// describes payout amounts 
		JLabel payoutInfo = new JLabel("Payout Info:" ) ;
		JLabel pair = new JLabel("Pair: "+ PAIR) ;
		JLabel twoPair = new JLabel("Two Pair: " + TWO_PAIR) ;
		JLabel threeKind = new JLabel("Three of a Kind: " + THREE_KIND) ;
		JLabel straight = new JLabel("Straight: " + STRAIGHT) ;
		JLabel flush = new JLabel("Flush: " + FLUSH) ;
		JLabel fullHouse = new JLabel("Full House: " + FULL_HOUSE) ;
		JLabel fourKind = new JLabel("Four of a Kind: " + FOUR_KIND) ;
		JLabel straightFlush = new JLabel("Straight Flush: " + STRAIGHT_FLUSH) ;
		JLabel royalFlush = new JLabel("Royal Flush: " + ROYAL_FLUSH) ;
		

		
		// Declares check boxes for replace
		JCheckBox replace1 = new JCheckBox("Replace") ;
		JCheckBox replace2 = new JCheckBox("Replace") ;
		JCheckBox replace3 = new JCheckBox("Replace") ;
		JCheckBox replace4 = new JCheckBox("Replace") ;
		JCheckBox replace5 = new JCheckBox("Replace") ;
		
		// Declares buttons to play game
		JButton stand = new JButton("Stand") ;
		JButton draw = new JButton("Draw") ;
		JButton deal = new JButton("Deal") ;
		JButton payoutButton = new JButton("Payout") ;
		
		JPanel card1 = new JPanel() ;
		JPanel card2 = new JPanel() ;
		JPanel card3 = new JPanel() ;
		JPanel card4 = new JPanel() ;
		JPanel card5 = new JPanel() ;
		
		JPanel javaDollarPan = new JPanel() ;
		JPanel javaDollarEarned = new JPanel() ;
		
		JLabel javaDollarDisplay = new JLabel(javaDollar + " Java Dollars") ;
		JLabel javaDollarEarnedLbl = new JLabel("You have earned: " + javaEarned + " Java Dollars.") ;
		
		
	VideoPoker() {
		
		// closes game
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// sets background
		JPanel back = new JPanel() ;
		back.setBackground(Color.green) ;
		back.setPreferredSize(new Dimension(WIDTH, HEIGHT));
		
		// set payout info box
		JPanel payout = new JPanel() ;
		payout.setBackground(Color.red) ;
		payout.setPreferredSize(new Dimension(INFO_WIDTH, INFO_HEIGHT));
		

		// adds panels for payout info, javaDollars, and earned javaDollars
		back.add(payout) ;
		back.add(javaDollarPan) ;
		back.add(javaDollarEarned) ;

		frame.getContentPane().add(back) ;
		
		pokerHand.randomHand() ;
		
		// initializes first game
		card1.add(pokerHand.showCard(0)) ;
		card2.add(pokerHand.showCard(1)) ;
		card3.add(pokerHand.showCard(2)) ;
		card4.add(pokerHand.showCard(3)) ;
		card5.add(pokerHand.showCard(4)) ;
			
		// adds info to panel
		payout.add(payoutInfo) ;
		payout.add(pair) ;
		payout.add(twoPair) ;
		payout.add(threeKind) ;
		payout.add(straight) ;
		payout.add(flush) ;
		payout.add(fullHouse) ;
		payout.add(fourKind) ;
		payout.add(straightFlush) ;
		payout.add(royalFlush) ;
		
		// creates panel to show current payout of java dollars
		
		javaDollarPan.setBackground(Color.orange) ;
		javaDollarPan.setPreferredSize(new Dimension(PAY_WIDTH, PAY_HEIGHT));
		javaDollarPan.add(javaDollarDisplay) ;
		
		// creates a panel to show how much player has earned from hand
		javaDollarPan.setBackground(Color.orange) ;
		javaDollarPan.setPreferredSize(new Dimension(PAY_WIDTH, PAY_HEIGHT));
		javaDollarEarned.add(javaDollarEarnedLbl) ;
		

		// adds listners to buttons
		stand.addActionListener(new standListen()) ;
		draw.addActionListener(new drawListen());
		deal.addActionListener(new dealListen()) ;
		
		// adds listener for payout button
		payoutButton.addActionListener(new payOutListen()) ;
		
		// disables stand, draw, payout buttons until after game has been played
		payoutButton.setEnabled(false);
		stand.setEnabled(false);
		draw.setEnabled(false);
		
		// adds cards to frame
		back.add(card1) ;
		back.add(card2) ;
		back.add(card3) ;
		back.add(card4) ;
		back.add(card5) ;
		
		// adds buttons to frame
		back.add(replace1) ;
		back.add(replace2) ;
		back.add(replace3) ;
		back.add(replace4) ;
		back.add(replace5) ;
		back.add(stand) ;
		back.add(draw) ;
		back.add(deal) ;
		back.add(payoutButton) ;
		frame.pack() ;
		frame.setVisible(true) ;

	}// end public static void main
	
	// payOutListen
	// adds java dollars earned to current amount of java dollars used for play
	// earned dollars are reset to 0, and text is updated.
	private class payOutListen implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			javaDollar += javaEarned ;		// add earned to funds
			javaEarned = 0 ;				// reset earned
			javaDollarDisplay.setText(javaDollar + " Java Dollars"); // update text
			javaDollarEarnedLbl.setText("You have earned: " + javaEarned + " Java Dollars.");
			
			// re-enables deal button after adding more funds to java Dollars
			if (javaDollar > 0)
				deal.setEnabled(true) ;
		}
	} // end payOutListen

	
	// dealListen
	// deals 5 new random cards
	private class dealListen implements ActionListener
	{
		public void actionPerformed(ActionEvent event){
			// if player has credits to play, player bets 1 java dollar to play
			if (javaDollar > 0) {
				javaDollar-- ;
				// sets up new game
				card1.removeAll();		// card panels are removed
				card2.removeAll();
				card3.removeAll();
				card4.removeAll();
				card5.removeAll();
				
				pokerHand.reset();		// deck is reset
					
				pokerHand.randomHand() ;// hand is randomized with new cards
				
				card1.add(pokerHand.showCard(0)) ;	// new card panels are added
				card2.add(pokerHand.showCard(1)) ;
				card3.add(pokerHand.showCard(2)) ;
				card4.add(pokerHand.showCard(3)) ;
				card5.add(pokerHand.showCard(4)) ;
				
				// update javaDollars
				javaDollarDisplay.setText(javaDollar + " Java Dollars");
				frame.pack() ;
			}
				
			else {		// disables deal button after player has run out of funds
				javaDollarDisplay.setText("Thank you for playing.");	// displays thank you text
			deal.setEnabled(false) ;		// buttons are disabled
			}
			stand.setEnabled(true); // renables stand and draw buttons
			draw.setEnabled(true) ;
			
			// resets (unchecks) checkboxes for replace checkboxes
						replaceBool1 = false ;
						replaceBool2 = false ;
						replaceBool3 = false ;
						replaceBool4 = false ;
						replaceBool5 = false ;
						replace1.setSelected(false);
						replace2.setSelected(false);
						replace3.setSelected(false);
						replace4.setSelected(false);
						replace5.setSelected(false);
		}
		
	} // end deal listen
	
	// standListen
	// calculates hand.
	private class standListen implements ActionListener
	{
		public void actionPerformed(ActionEvent event){
			
			// enables payout button
			payoutButton.setEnabled(true);
			
			
			pokerHand.sortHand() ;   		     // sorts internal hand array
			javaEarned = pokerHand.valueHand() ; // assigns hand amount to earned funds
			javaDollarEarnedLbl.setText("You have earned: " + javaEarned + " Java Dollars."); // updates text
			stand.setEnabled(false);		// disables stand button
			draw.setEnabled(false) ;		// disables draw button
			
			
			// resets checkboxes for replace checkboxes
			replaceBool1 = false ;
			replaceBool2 = false ;
			replaceBool3 = false ;
			replaceBool4 = false ;
			replaceBool5 = false ;
			replace1.setSelected(false);
			replace2.setSelected(false);
			replace3.setSelected(false);
			replace4.setSelected(false);
			replace5.setSelected(false);
			
		}
	} //end standListen
	
	
	// draw listen
	// swaps out any cards that have been selected and calculates hand.
	private class drawListen implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			
			payoutButton.setEnabled(true);     // enables payout button
			
			if (replace1.isSelected())    // sets swap booleans to true is check boxes are selected
				replaceBool1 = true ;
			
			if (replace2.isSelected())
				replaceBool2 = true ;
			
			if (replace3.isSelected())
				replaceBool3 = true ;
			
			if (replace4.isSelected())
				replaceBool4 = true ;
		
			if (replace5.isSelected())
				replaceBool5 = true ;
			
			// swaps card based on check boxes
			if (replaceBool1) {
				pokerHand.swapCard(0) ; // swaps card 1
				card1.removeAll();
				card1.add(pokerHand.showCard(0)) ;
			} // replaceBool1
			
			if (replaceBool2) {
				pokerHand.swapCard(1) ; // swaps card 2
				card2.removeAll();
				card2.add(pokerHand.showCard(1)) ;
			} // replaceBool2
			
			if (replaceBool3) {
				pokerHand.swapCard(2) ; // swaps card 3
				card3.removeAll();
				card3.add(pokerHand.showCard(2)) ;
			} // replaceBool3
			
			if (replaceBool4) { 
				pokerHand.swapCard(3) ; // swaps card 4
				card4.removeAll();
				card4.add(pokerHand.showCard(3)) ;
			} // replaceBool4
			
			if (replaceBool5) { 
				pokerHand.swapCard(4) ; // swaps card 5
				card5.removeAll();
				card5.add(pokerHand.showCard(4)) ;
			} // replaceBool5
			
			
			pokerHand.sortHand() ;    // sorts hand
			javaEarned = pokerHand.valueHand() ;  // assigns hand value to earned funds
			javaDollarEarnedLbl.setText("You have earned: " + javaEarned + " Java Dollars.");  // updates text
			stand.setEnabled(false);		// disables stand and draw buttons
			draw.setEnabled(false) ;
			frame.pack() ;			
			
			
			// resets checkboxes for replace checkboxes
			replaceBool1 = false ;
			replaceBool2 = false ;
			replaceBool3 = false ;
			replaceBool4 = false ;
			replaceBool5 = false ;
			replace1.setSelected(false);
			replace2.setSelected(false);
			replace3.setSelected(false);
			replace4.setSelected(false);
			replace5.setSelected(false);
			
			
		} // end actionPerformed
	}// end swap1
	
} // end class VideoPoker


