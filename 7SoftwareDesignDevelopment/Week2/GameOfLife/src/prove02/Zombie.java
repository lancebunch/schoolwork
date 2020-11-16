package prove02;

import java.awt.*;

public class Zombie extends Creature implements Aggressor, Movable {

    // Other inherited functions that need to be set from the Creature class
    public Shape getShape() { return Shape.Square; }

    public Color getColor() { return new Color(0, 50, 150); }

    public Boolean isAlive() { return _health > 0; }

    // Zombie starts with a health of 5
    public Zombie() { _health = 5; }

    public void attack(Creature target) {
        // If the zombie is on a square with nothing else...
        if (target == null)
        {
            // Don't do anything.
            return;
        }
        // Otherwise if is lands on something other than a plant
        else if (!(target instanceof Plant)) {
            // Do 10 points of damage.
            target.takeDamage(10);
        }
    }

    // implementing Movable function
    public void move() { _location.x++; }
}
