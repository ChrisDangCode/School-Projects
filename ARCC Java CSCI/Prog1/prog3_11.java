
import java.awt.*;
import javax.swing.*;

public class prog3_11 {

	public static void main(String[] args) {
		
		ImageIcon waterfall = new ImageIcon("WaterFall.jpg") ;
		ImageIcon flower = new ImageIcon("LittleFlower.jpg") ;
		ImageIcon guitar = new ImageIcon("Guitar.jpg") ;
		ImageIcon canon = new ImageIcon("CanonAE1.jpg") ;
		
		//Creates Frame 
		JFrame frame = new JFrame("Frame 1") ;
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
		
		//First panel of frame 
		//First image added
		JPanel panel1 = new JPanel() ;
		JLabel label1 = new JLabel(waterfall) ;
		panel1.add(label1) ;
		
		//Second image added 
		JLabel label2 = new JLabel(flower) ;
		panel1.add(label2) ;
		
		//Second panel of frame, first image
		JPanel panel2 = new JPanel() ;
		JLabel label3 = new JLabel(guitar) ;
		panel2.add(label3) ;
		
		//Second panel, second image
		JLabel label4 = new JLabel(canon) ;
		panel2.add(label4) ;
		
		//Primary panel of frame 
		JPanel back1 = new JPanel() ;
		back1.setBackground(Color.black) ;
		back1.setPreferredSize(new Dimension(1100, 270)) ;
		back1.add(panel1) ;
		back1.add(panel2) ;

		frame.getContentPane().add(back1) ;
		frame.setVisible(true);
		frame.pack();
		
	}

}
