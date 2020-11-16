package prove02;

import java.awt.*;
import java.util.Random;

public class PlagueBearer extends Creature implements Aggressor, Aware, Movable, Spawner {
    private Random _rand = new Random();
    private Direction preferredDirection;
    private boolean thePlague = false;

    // Implementing Creature methods
    public Shape getShape() { return Shape.Circle; }

    public Color getColor() { return new Color(0, 150, 75); }

    public Boolean isAlive() { return _health > 0; }

    // Default Constructor
    public PlagueBearer() {
        _health = 10;
        switch(_rand.nextInt(4)) {
            case 0:
                // _location.x++
                preferredDirection = Direction.right;
                break;
            case 1:
                // _location.x--
                preferredDirection = Direction.left;
                break;
            case 2:
                // _location.y--
                preferredDirection = Direction.above;
                break;
            case 3:
                //_location.y++;
                preferredDirection = Direction.below;
                break;
            default:
                break;
        }
    }

    // Implementing Aggressor function.
    public void attack(Creature target) {
        if (target == null) {
            return;
        }
        else if (target instanceof Animal || target instanceof Wolf) {
            target.takeDamage(5);
            thePlague = true;
        }
    }

    // Implementing Aware function.
    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {
        if (preferredDirection == Direction.above) {
            if (above instanceof Animal) {
                preferredDirection = Direction.above;
            }
            else if (right instanceof Animal) {
                preferredDirection = Direction.right;
            }
            else if (below instanceof Animal) {
                preferredDirection = Direction.below;
            }
            else if (left instanceof Animal) {
                preferredDirection = Direction.left;
            }
        }
        else if (preferredDirection == Direction.right) {
            if (right instanceof Animal) {
                preferredDirection = Direction.right;
            }
            else if (below instanceof Animal) {
                preferredDirection = Direction.below;
            }
            else if (left instanceof Animal) {
                preferredDirection = Direction.left;
            }
            else if (above instanceof Animal) {
                preferredDirection = Direction.above;
            }
        }
        else if (preferredDirection == Direction.below) {
            if (below instanceof Animal) {
                preferredDirection = Direction.below;
            }
            else if (left instanceof Animal) {
                preferredDirection = Direction.left;
            }
            else if (above instanceof Animal) {
                preferredDirection = Direction.above;
            }
            else if (right instanceof Animal) {
                preferredDirection = Direction.right;
            }
        }
        else if (preferredDirection == Direction.left) {
            if (left instanceof Animal) {
                preferredDirection = Direction.left;
            }
            else if (above instanceof Animal) {
                preferredDirection = Direction.above;
            }
            else if (right instanceof Animal) {
                preferredDirection = Direction.right;
            }
            else if (below instanceof Animal) {
                preferredDirection = Direction.below;
            }
        }
    }

    // Implementing Move function
    public void move() {
        switch(preferredDirection) {
            case right:
                _location.x++;
                break;
            case left:
                _location.x--;
                break;
            case above:
                _location.y--;
                break;
            case below:
                _location.y++;
                break;
            default:
                break;
        }
    }

    // Another implementation of the spawnNewCreature function
    public Creature spawnNewCreature() {
        if (thePlague) {
            thePlague = false;
            Zombie spawn = new Zombie();
            spawn.setLocation(new Point(_location.x - 1, _location.y));
            return spawn;
        }
        return null;
    }
}
