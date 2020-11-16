package prove02;

import java.awt.*;
import java.util.Random;

public class Wolf extends Creature implements Aggressor, Aware, Movable, Spawner {
    private Random _rand = new Random();
    private Direction preferredDirection;
    private boolean fertile = false;

    // Inherited functions that need to be set from the Creature class
    public Shape getShape() { return Shape.Square; }

    public Color getColor() { return new Color(150, 150, 150); }

    public Boolean isAlive() { return _health > 0; }

    // Wolf starts with a health of 10, start with a random preferredDirection
    public Wolf() {
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
        if (target instanceof Animal) {
            target.takeDamage(5);
            if (!target.isAlive()) {
                fertile = true;
            }
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

    // Implementing Movable function.
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

    // Implementing Spawner Function
    public Creature spawnNewCreature() {
        if (fertile) {
            fertile = false;
            Wolf spawn = new Wolf();
            spawn.setLocation(new Point(_location.x - 1, _location.y));
            return spawn;
        }
        return null;
    }
}
