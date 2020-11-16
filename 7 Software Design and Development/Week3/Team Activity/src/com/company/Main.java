package com.company;

import com.google.gson.Gson;

public class Main {

    static final String SAVE_FILE = "/Users/Lance Bunch/Desktop/saveGame.txt";

    public static void main(String[] args) {

        // Create the player
        Player p = new Player("Steve", 50, 1000, 10);

        // Print it out to verify its values. We can put it directly in the println()
        // function because Player overrides the Object class' toString() method.
        // See https://docs.oracle.com/javase/7/docs/api/java/lang/Object.html#toString()
        System.out.println(p);

        // Create a game using our player, then sae the game to a file.
        Game theGame = new Game(p);
        theGame.saveGame(SAVE_FILE);

        // Create a new game using the file we created, then print out the player object
        // the game holds to make sure it matches what we had originally.
        Game newGame = Game.loadGame(SAVE_FILE);
        System.out.println(newGame.getPlayer());

        // STRETCH CHALLENGE //

        // Add some equipment to the player
        p.addEquipment("Sword", 10);
        p.addEquipment("Shield", 40);
        p.addEquipment("Lunch", 100);
        System.out.println(p);

        theGame.saveGame(SAVE_FILE);
        Game thirdGame = Game.loadGame(SAVE_FILE);
        System.out.println(thirdGame.getPlayer());
    }
}
