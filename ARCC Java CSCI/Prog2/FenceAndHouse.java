//******************************************************************************
// FenceAndHouse.java		Chris Dang 			Class: CSCI 1125 Spring 2015
//******************************************************************************
// Program will draw a house behind a fence
// 

import java.awt.* ;

import javax.swing.JApplet;

public class FenceAndHouse extends JApplet{
		
		public void paint (Graphics page)
		{
			//constants used for fence
			final int WIDTH = 25 ;
			final int HEIGHT = 250 ;
			final int POSTS = 10 ;
			final int BOARDS = 3 ;

			//constants used for house
			final int HOUSE_SIZE = HEIGHT / 2 ;
			final int HOUSE_HEIGHT = HEIGHT / 3 ;
			final int DOOR_X_POSITION = HEIGHT / 2 + WIDTH + WIDTH + WIDTH + (WIDTH /2) ;
			final int DOOR_Y_POSITION = HEIGHT /2 + WIDTH + (WIDTH /2) ;
			final int DOOR_HEIGHT = WIDTH * 2 ;
			final int WINDOW_POSITION = HEIGHT / 2 + WIDTH ;
			final int ROOF_X_POSITION = HEIGHT / 2 - WIDTH ;
			final int ROOF_Y_POSITION = WIDTH * 4 ;
			final int ROOF_WIDTH = HEIGHT / 2 + WIDTH + WIDTH ;
			final int KNOB_X_POSITION = HEIGHT / 2 + WIDTH + WIDTH + WIDTH + WIDTH ;
			final int KNOB_Y_POSITION = HEIGHT - (WIDTH * 3) ;
			final int DOOR_KNOB = 5 ;
			
			//Draws House----------------------
			
			// House Frame
			page.setColor(Color.cyan);
			page.fillRect(HOUSE_SIZE, HOUSE_SIZE, HOUSE_SIZE, HOUSE_HEIGHT ); 
			
			// Door
			page.setColor(Color.gray);
			page.fillRect(DOOR_X_POSITION, DOOR_Y_POSITION, WIDTH, DOOR_HEIGHT); 
			
			// Window
			page.setColor(Color.yellow);
			page.fillRect(WINDOW_POSITION, WINDOW_POSITION, DOOR_HEIGHT, WIDTH);  

			// Roof
			page.setColor(Color.black);
			page.fillRect(ROOF_X_POSITION, ROOF_Y_POSITION , ROOF_WIDTH, WIDTH);  
			
			// Doorknob
			page.fillOval(KNOB_X_POSITION, KNOB_Y_POSITION, DOOR_KNOB, DOOR_KNOB);   
			
			
			
			//Draws Fence-----------------------
			setBackground(Color.green) ;
			
			//creates vertical posts				
			page.setColor(Color.white) ;
			for (int i = 1; i <= POSTS; i++)
				page.fillRect(((WIDTH + WIDTH) * i), WIDTH, WIDTH, HEIGHT) ;
			// x-coordinate has twice the width so that it creates the first post
			// followed by a space so that the next post is created after the space
			
			//creates horizontal boards
			for (int j = 0; j < BOARDS; j++)
				page.fillRect(WIDTH, (WIDTH + WIDTH + (j * (HEIGHT - WIDTH))), (WIDTH + (WIDTH * POSTS * 2)), WIDTH) ;
			// y-coordinate starts with double the width so that the top board is 
			// down the width of one post.
			// The next board follows at the bottom of the fence

			// The width of the boards varies based on the number of posts.
			// The width of the boards is twice the number of posts 
			// (to account for the spaces), plus an additional width of a post to have
			// extra space at the end of the boards.		  
			 
	}
}
