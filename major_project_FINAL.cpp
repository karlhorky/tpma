//==============================================================================
//------------------------------------------------------------------------------
//
//                         Tricky Pete's Magical Adventure
//
//
//   Finally, after what seemed like years of work, it's finally here. From the
// critically acclaimed developers of titles such as MsWear3 and Assignment
// 3.49 comes the mind-blowing title Tricky Pete's Magical Adventure. Including
// TWO-colour TEXT-BASED graphics, this new game is sure to please even the most
// distinguishing gamers.
//
//  Well, we finally finished. It's good to be done. Now you better like it.
//
//
//  Completed on June 16, 2003 by Karl Horky and Drew Hansen
//
//------------------------------------------------------------------------------
//==============================================================================


//==============================================================================
//
//                              About Commenting
//
//   Certain comments will be omitted and replaced by a number as a result of
// the frequency of their use. A table of omitted comments can be found below.
//
//
//           .A.  -   the variable for the player's choice of move
//           .B.  -   for centering
//           .C.  -   gives the player time to read what's being printed
//           .D.  -   starts a loop to check when the player has input the right
//                    number(s)
//           .E.  -   accepts input into the earlier-declared variable
//           .F.  -   ... and then tests that variable for the input
//           .G.  -   Tells the player to choose within a valid number range
//           .H.  -   Different paths for broken feet and non-broken feet
//
//==============================================================================




#include <iostream.h>
#include <stdlib.h>

#include <time.h>
#include <windows.h>


void init(void);
    //nothing

void pickLock(bool);
    //breakFoot

void basement(bool);
    //breakFoot

void cellphoneCall(int, bool, bool, bool);
    //noneRunHop, breakFoot, ductYet, gun

void grates(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void lightFixture(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void airDucts(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void insideDuct(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void firstIntersection(int, bool, bool, bool, bool);
    //direction, breakFoot, outsideYet, ductYet, gun

void stairsDuct(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void basementLeave(bool, bool, bool, bool);
    //breakFoot, outsideYet, ductYet, gun

void fightGuards(int, bool, bool, bool);
    //iteration, breakFoot, ductYet, gun

void peppersprayEscape(bool, bool);
    //breakFoot, gun

void sidehallRun(bool, bool);
    //breakFoot, gun

void hallwayEscape(bool, bool, bool, bool, bool);
    //killGuard, hallway(goto?), ductYet, breakFoot, gun

void stairs(bool, bool);
    //breakFoot, gun



void defaultCase(int);
    //maximum

void startAgain(void);
    //nothing

void spacer(int);
    //size



int main()
  {

  //initiating function
  init();

  //just so that there aren't problems when the program finishes
  return 0;

  }

void init()
  {
  // .A.
  char moveChoice;

  // after starting the game again, you don't want a broken foot right away, do
  // you?
  bool breakFoot = false;

  // .B.
  spacer(15);

  cout << "Tricky Pete's" << endl;

  // .C.
  Sleep(1500);

  // .B.
  spacer(17);

  cout << "-=-=-=-=-=-=-=-=-" << endl;

  // .C.
  Sleep(1500);

  // .B.
  spacer(17);

  cout << "Magical Adventure" << endl;

  // .C.
  Sleep(2300);

  cout << endl << endl;

  cout << "You are Tricky Pete. After a wild and crazy night where you ";
  cout << "ended up drinking a 15-pack of Drew Dew, you wake up to find ";
  cout << "yourself in a dark cramped steel safe.";

  // .C.
  Sleep(8000);

  cout << endl << endl << "What would you like to do?" << endl << endl;


  cout << "1 - Yell for help" << endl;
  cout << "2 - Pick the lock with the pin from your pants" << endl;
  cout << "3 - Try the cell phone in your pocket" << endl;
  cout << "4 - Try to kick your way out" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        cout << "You yell for help but nobody comes to the rescue." << endl;

        break;

      case '2':
        pickLock(breakFoot);

        break;

      case '3':

        // The last two variables haven't been defined in this function yet,
        // and shouldn't be true when you're just initiating the game, so they
        // are set to false. The reason that breakFoot isn't just replaced with
        // a false is below.
        cellphoneCall(1, breakFoot, false, false);

        break;

      case '4':
        cout << "You try to kick your way out of the steel safe, but end up ";
        cout << "breaking your foot." << endl;

        // Why breakFoot isn't just replaced with a false. Once the loop is
        // executed, breakFoot now equals true, and is passed along to pickLock
        // or cellphoneCall
        breakFoot = true;

        break;

      default:
        // .G.
        defaultCase(4);

        break;

      }

    // If the player picks the choices of either futilely yelling or breaking
    // his foot, alert the player that the game still continues with a
    // "Try again."
    if (moveChoice == '1' || moveChoice == '4')
      cout << "Try again." << endl;
    } while (moveChoice != '2' && moveChoice != '3');

  }


void pickLock(bool breakFoot)
  {
  // What you guess the tumbler's height is, and what the tumbler's height
  // really is
  int heightGuess, tumblerHeight;

  // For the randomness of ever-changing time
  unsigned seed = time(NULL);

  // Randomize with the time-based seed
  srand(seed);

  // tumblerHeight is now a random number between one and ten, inclusive
  tumblerHeight = rand()%10 + 1;

  // .H.
  if (breakFoot == true)
    cout << "You try to pick the lock, but your broken foot hinders you.";

  // .H.
  else
    {
    cout << "You try to pick the lock, but can't seem to get a good angle on ";
    cout << "it.";
    }

    cout << endl << "Guessing the last tumbler's height will be hard";
    cout << " (1-10 mm):";

  // starts a loop to keep checking if the player got the right number
  do
    {
    // The guess goes in.
    cin >> heightGuess;

    // If the guess is right...
    if (heightGuess == tumblerHeight)
      {
      cout << endl << "Yes! You got it! The door's open!" << endl;

      basement(breakFoot);
      break;

      }

    // If the guess is WAY off...
    else if (heightGuess < 1 || heightGuess > 10)
      cout << "Remember - only 1 to 10 mm." << endl << "Try again:";

    // And if the guess is just a bit wrong
    else
      cout << "Damn. Wrong height." << endl << "Try again:";
    } while (heightGuess != tumblerHeight);

  }



void basement(bool breakFoot)
  {

  // .A.
  char moveChoice;

  cout << endl;
  cout << "As you open the door, you become aware that it is brightly lit ";
  cout << "outside. Your eyes will take a minute to adjust." << endl << endl;

  for (int i=0;i<10;i++)
    {                                   //Loops a printout of a star and a one
    Sleep(1000);                        //second pause ten times alluding to
    cout << "*";                        //time going by
    }

  cout << endl << endl << "Your eyes adjust to the light, and you make out ";
  cout << "the slightest bit of shoulder of each of the guards directly ";
  cout << "outside the doorway to the room. You only have the bent pin ";
  cout << "and what you're wearing";

  // .H.
  if (breakFoot == true) cout << ", and your foot is useless." << endl;
  else cout << ".";

  // .C.
  Sleep(9500);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  // .H.
  if (breakFoot == false)
    {
    cout << "1 - Make a rush at the guards with your pin" << endl;
    cout << "2 - Make a mad dash out the door" << endl;
    cout << "3 - Look closer at your surroundings" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          fightGuards(1, breakFoot, false, false);

          break;

        case '2':
          cellphoneCall(3, breakFoot, false, false);

          break;

        case '3':
          grates(breakFoot, false, false, false);

          break;

        default:
          // .G.
          defaultCase(3);

          break;
        }
      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3');


    }

  // .H.
  else     // If you have a broken foot
    {
    cout << "1 - Make a hopping rush at the guards with your pin" << endl;
    cout << "2 - Hop out the door and hope that the guards won't" << endl;
    cout << "notice you" << endl;
    cout << "3 - Look closer at your surroundings" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          fightGuards(1, breakFoot, false, false);

          break;

        case '2':
          cellphoneCall(2, breakFoot, false, false);

          break;

        case '3':
          grates(breakFoot, false, false, false);

          break;

        default:
          // .G.
          defaultCase(3);

          break;
        }
      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3');
    }

  }



void cellphoneCall(int noneRunHop, bool breakFoot, bool ductYet, bool gun)
  {

  // .A.
  char moveChoice;

  // Testing different ways of getting to the generic response below
  if (noneRunHop == 1)
    {
    cout << "You call your best friend and tell him your problem. He doesn't ";
    cout << "believe you, and ends up hanging up on you." << endl << endl;

    // .C.
    Sleep(5000);

    cout << "You start to hear shuffling outside, and then are blinded by a ";
    cout << "bright light as the door opens. As your eyes are still ";
    cout << "adjusting, you are hustled out into the scathing light by ";
    cout << "unknown forces. " << endl << endl;

    // .C.
    Sleep(9500);


    cout << "Three minutes later, your eyes start to focus, and you realize ";
    cout << "you're being taken down a long, dark hallway by three guards.";
    cout << endl << endl;

    // .C.
    Sleep(5000);
    }

  // Another way
  else if (noneRunHop == 2)
    {
    cout << "You hop silently out the door, hoping that the guards ";
    cout << "are asleep or have closed eyes." << endl << endl;

    // .C.
    Sleep(5000);

    cout << "Unfortunately, this is not the case, as you soon learn. They ";
    cout << "apprehend you roughly, and after another guard joins them, ";
    cout << "bring you down a long dark hallway." << endl << endl;

    // .C.
    Sleep(8000);
    }

  // And another way
  else
    {
    cout << "You run as fast as you can out the door, and hear yells behind ";
    cout << "you. The guards start following you at a relative speed, but are ";
    cout << "not a threat in terms of your apprehension." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "Since you are watching them so intently, you don't realize that ";
    cout << "you're coming up on another guard until he's bearing down on ";
    cout << "you. He catches you by the arm and swings you into a headlock.";
    cout << endl << endl;

    // .C.
    Sleep(9000);

    cout << "The other guards soon catch up and help the third take you down ";
    cout << "a long dark hallway." << endl << endl;

    // .C.
    Sleep(5000);
    }

  cout << "Luckily, they didn't see your pin before you were able to ";
  cout << "conceal it. At regular intervals, there are side halls to your ";
  cout << "left that would provide good escape routes. One of the guards also ";
  cout << "has a can of pepperspray on his belt.";

  // .C.
  Sleep(9500);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  // .H.
  if (breakFoot == false)
    cout << "1 - Make a bolt for one of the hallways";

  // .H.
  else
    {
    cout << "1 - Attempt a hopping escape down one of" << endl;
    cout << "the hallways";
    }

  cout << endl;

  cout << "2 - Use the pepperspray as an escape weapon" << endl;
  cout << "3 - Try to take the three guards on with your" << endl;
  cout << "concealed pin" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        sidehallRun(breakFoot, gun);

        break;

      case '2':
        peppersprayEscape(breakFoot, gun);

        break;

      case '3':
        fightGuards(2, breakFoot, ductYet, gun);

        break;

      default:
        // .G.
        defaultCase(3);

        break;
      }
    } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3');

  }



void grates(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {

  // .A.
  char moveChoice;

  // If you haven't been outside or in the duct yet
  if (outsideYet == false && ductYet == false)
    {
    cout << "You look around again, and notice the room is lit by four ";
    cout << "fluorescent light fixtures with metal grates over them. " << endl;
    cout << endl;

    // .C.
    Sleep(5000);

    cout << "Near the floor on your right is another grate, except this ";
    cout << "one seems to be covering the opening to an air duct. The ";
    cout << "only other thing in the room is a thin aluminum chair.";

    // .C.
    Sleep(8000);

    cout << endl << endl << "What would you like to do?" << endl << endl;

    cout << "1 - Test the grate over the lights" << endl;
    cout << "2 - Test the grate over the air duct" << endl;
    cout << "3 - Try to break the light grate with" << endl;
    cout << "the chair" << endl;
    cout << "4 - Try to break the air duct grate" << endl;
    cout << "with the chair" << endl;
    cout << "5 - Don't worry about the grates - " << endl;
    cout << "focus on getting out of the room" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          lightFixture(breakFoot, outsideYet, ductYet, gun);

          break;

        case '2':
          airDucts(breakFoot, outsideYet, ductYet, gun);

          break;

        case '3':
          cout << "You pick up the chair and hurl it at the grate over the ";
          cout << "overhead lights. It doesn't seem to have much effect other ";
          cout << "than a loud clang. You are about to think of another ";
          cout << "method of removing the grate when the two guards rush into ";
          cout << "the room." << endl << endl;

          // .C.
          Sleep(10500);

          cout << "The chair is still in reach, so you pick it up and hurl it ";
          cout << "at one of the guards. As the one's dodging the projectile, ";
          cout << "you come at the other guard with the pin." << endl << endl;

          // .C.
          Sleep(5000);

          cout << "You make it halfway there before being cut down in a hail ";
          cout << "of gunfire. You fall to the ground, your head smacking the ";
          cout << "concrete. Just as your vision begins to fade, you can feel ";
          cout << "the beginnings of warm liquid seeping past your neck.";

          // .C.
          Sleep(1000);

          startAgain();

          break;

        case '4':
          cout << "You pick up the chair and hurl it at the grate over the ";
          cout << "air duct. It doesn't seem to have much effect other ";
          cout << "than a loud clang. You are about to think of another ";
          cout << "method of removing the grate when the two guards rush into ";
          cout << "the room." << endl << endl;

          // .C.
          Sleep(10500);

          cout << "The chair is still in reach, so you pick it up and hurl it ";
          cout << "at one of the guards. As the one's dodging the projectile, ";
          cout << "you come at the other guard with the pin." << endl << endl;

          // .C.
          Sleep(5000);

          cout << "You make it halfway there before being cut down in a hail ";
          cout << "of gunfire. You fall to the ground, your head smacking the ";
          cout << "concrete. Just as your vision begins to fade, you can feel ";
          cout << "the beginnings of warm liquid seeping past your neck.";

          // .C.
          Sleep(1000);

          startAgain();

          break;

        case '5':
          basementLeave(breakFoot, outsideYet, ductYet, gun);

          break;

        default:
          // .G.
          defaultCase(5);

          break;
        }
      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3' &&
      moveChoice != '4' && moveChoice != '5');
    }


  // If you've been in the duct, but not outside yet
  else if (ductYet == true && outsideYet != true)
    {
    cout << "You look around again, and notice the room is lit by four ";
    cout << "fluorescent light fixtures with metal grates over them. ";
    cout << "Near the floor on your right is the open air duct grate.";
    cout << "The only other thing in the room is a thin aluminum chair.";

    // .C.
    Sleep(9500);

    cout << endl << endl << "What would you like to do?" << endl << endl;

    cout << "1 - Test the grate over the lights" << endl;
    cout << "2 - Go back in the air duct" << endl;
    cout << "3 - Try to break the light grate with" << endl;
    cout << "the chair" << endl;
    cout << "4 - Don't worry about the grates - " << endl;
    cout << "focus on getting out of the room" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          lightFixture(breakFoot, outsideYet, ductYet, gun);

          break;

        case '2':
          airDucts(breakFoot, outsideYet, ductYet, gun);

          break;

        case '3':
          cout << "You pick up the chair and hurl it at the grate over the ";
          cout << "overhead lights. It doesn't seem to have much effect other ";
          cout << "than a loud clang. You are about to think of another ";
          cout << "method of removing the grate when the two guards rush into ";
          cout << "the room." << endl << endl;

          // .C.
          Sleep(8500);

          cout << "The chair is still in reach, so you pick it up and hurl it ";
          cout << "at one of the guards. As the one's dodging the projectile, ";
          cout << "you come at the other guard with the pin." << endl << endl;

          // .C.
          Sleep(5000);

          cout << "You make it halfway there before being cut down in a hail ";
          cout << "of gunfire. You fall to the ground, your head smacking the ";
          cout << "concrete. Just as your vision begins to fade, you can feel ";
          cout << "the beginnings of warm liquid seeping past your neck.";

          // .C.
          Sleep(1000);

          startAgain();

          break;

        case '4':
          basementLeave(breakFoot, outsideYet, ductYet, gun);

          break;

        default:
          // .G.
          defaultCase(4);

          break;
        }
      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3'
      && moveChoice != '4');

    }

  // If you've been in the duct and outside
  else if (ductYet == true && outsideYet == true)
    {
    cout << "You look around again, and notice the room is lit by four ";
    cout << "fluorescent light fixtures with metal grates over them." << endl;
    cout << endl;

    // .C.
    Sleep(5000);

    cout << "Near the floor on your right is the open air duct grate.";
    cout << "The only other thing in the room is a thin aluminum chair. The ";
    cout << "guards outside are incapacitated, so you won't need to worry ";
    cout << "about them.";

    // .C.
    Sleep(9500);

    cout << endl << endl << "What would you like to do?" << endl << endl;

    cout << "1 - Test the grate over the lights" << endl;
    cout << "2 - Go back in the air duct" << endl;
    cout << "3 - Try to break the light grate with" << endl;
    cout << "the chair" << endl;
    cout << "4 - Go out into the hallway again" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          lightFixture(breakFoot, outsideYet, ductYet, gun);

          break;

        case '2':
          airDucts(breakFoot, outsideYet, ductYet, gun);

          break;

        case '3':
          cout << "You pick up the chair and hurl it at the grate over the ";
          cout << "overhead lights. It doesn't seem to have much effect other ";
          cout << "than a loud clang." << endl;

          break;

        case '4':
          basementLeave(breakFoot, outsideYet, ductYet, gun);

          break;

        default:
          // .G.
          defaultCase(4);

          break;
        }

        // If the player tries futilely throwing the chair at the lights grate,
        // alert the player that the game still continues with a "Try again."
        if (moveChoice == '3') cout << "Try again." << endl;

      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '4');

    }

  // If you've been outside, but not in the duct
  else if (outsideYet == true && ductYet != true)
    {
    cout << "You look around again, and notice the room is lit by four ";
    cout << "fluorescent light fixtures with metal grates over them." << endl;
    cout << endl;

    // .C.
    Sleep(5000);

    cout << "Near the floor on your right is another grate, except this ";
    cout << "one seems to be covering the opening to an air duct. The only ";
    cout << "other thing in the room is a thin aluminum chair." << endl << endl;

    // .C.
    Sleep(5000);

    cout << "The guards outside are incapacitated, so you won't need to worry ";
    cout << "about them.";

    // .C.
    Sleep(5000);

    cout << endl << endl << "What would you like to do?" << endl << endl;

    cout << "1 - Test the grate over the lights" << endl;
    cout << "2 - Test the grate over the air duct" << endl;
    cout << "3 - Try to break the light grate with" << endl;
    cout << "the chair" << endl;
    cout << "4 - Go out into the hallway again" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          lightFixture(breakFoot, outsideYet, ductYet, gun);

          break;

        case '2':
          airDucts(breakFoot, outsideYet, ductYet, gun);

          break;

        case '3':
          cout << "You pick up the chair and hurl it at the grate over the ";
          cout << "overhead lights. It doesn't seem to have much effect other ";
          cout << "than a loud clang." << endl;

          break;

        case '4':
          basementLeave(breakFoot, outsideYet, ductYet, gun);

          break;

        default:
          // .G.
          defaultCase(4);

          break;
        }
        if (moveChoice == '3') cout << "Try again." << endl;

      } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '4');

    }

  }



void lightFixture(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {
  // .A.
  char moveChoice;

  cout << "To your suprise, the grate over the lights is only held in place ";
  cout << "by four screws. They don't seem to be screwed in all that tightly, ";
  cout << "either." << endl << endl;

  // .C.
  Sleep(5500);

  cout << "You try undoing the screws with your thumb, and, to your ";
  cout << "even greater suprise, they come out. You take off the grate and ";
  cout << "see the two fluorescent bulbs and four dusty wires ";
  cout << "hanging to the side.";

  // .C.
  Sleep(9500);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  cout << "1 - Try to take down a bulb by hand" << endl;
  cout << "2 - Try to remove the wires" << endl;
  cout << "3 - Put the grate back and focus on" << endl;
  cout << "the air duct" << endl;
  cout << "4 - Put the grate back and focus on" << endl;
  cout << "getting out of the room" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        cout << "You try to take down the bulb but end up shocking ";
        cout << "yourself with 16 amps, resulting in your death.";

        startAgain();

        break;

      case '2':
        cout << "You try to take out the wires but in a shower of sparks ";
        cout << "you convulse to your death.";

        startAgain();

        break;

      case '3':
        airDucts(breakFoot, outsideYet, ductYet, gun);

        break;

      case '4':
        basementLeave(breakFoot, outsideYet, ductYet, gun);

        break;

      default:
        // .G.
        defaultCase(4);

        break;

      }
    } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3' &&
    moveChoice != '4');

  }

void airDucts(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {

  // .A.
  char moveChoice;

  // If you've been in the duct...
  if (ductYet == false)
    {
    cout << "To your surprise, the grate is open. You take a peek inside and ";
    cout << "see what you expected - a dusty airduct.";
    }
  else
    {
    cout << "You look back at the duct, thinking it might be the way to go ";
    cout << "after all";
    }

  // .C.
  Sleep(5000);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  cout << "1 - Climb on inside" << endl;
  cout << "2 - Close the grate and focus on escaping" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        insideDuct(breakFoot, outsideYet, ductYet, gun);

        break;

      case '2':
        basementLeave(breakFoot, outsideYet, ductYet, gun);

        break;

      default:
        // .G.
        defaultCase(2);

        break;
      }
    } while (moveChoice != '1' && moveChoice != '2');

  }



void insideDuct(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {

  // .A.
  char moveChoice;

  cout << "You squeeze into the duct and start crawling into the darkness. ";
  cout << "You wish you had a flashlight as you run into a intersection.";

  // .C.
  Sleep(5000);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  cout << "1 - Turn left" << endl;
  cout << "2 - Turn right" << endl;
  cout << "3 - Go back the way to came" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        firstIntersection(1, breakFoot, outsideYet, ductYet, gun);

        break;

      case '2':
        firstIntersection(2, breakFoot, outsideYet, ductYet, gun);

        break;

      case '3':
        grates(breakFoot, outsideYet, ductYet, gun);

        break;

      default:
        // .G.
        defaultCase(3);

        break;
      }
    } while(moveChoice != '1' && moveChoice != '2' && moveChoice != '3');
  }



void firstIntersection(int direction, bool breakFoot, bool outsideYet,
bool ductYet, bool gun)
  {
  bool loopCrawl = false;

  // Keep looping until direction equals one (left)
  do
    {
    // .A.
    char moveChoice;

    if (loopCrawl == true)
      direction = 1;

    if (direction == 1)
      {
      if (ductYet == false)
        {
        cout << "You start crawling left for a couple minutes when you start ";
        cout << "to hear a pitter patter. You stop crawling and unsheathe ";
        cout << "your pin. As you cautiously crawl on down the duct, you ";
        cout << "suddenly find yourself face to face with a large shadow.";

        // .C.
        Sleep(8000);

        cout << endl << endl << "What would you like to do?" << endl << endl;

        cout << "1 - Stab at the shadow with your pin" << endl;
        cout << "2 - Go back the way you came" << endl;
        cout << "3 - Look closer at it" << endl;

        // .D.
        do
          {
          // .E.
          cin >> moveChoice;

          // .F.
          switch (moveChoice)
            {
            case '1':
              stairsDuct(breakFoot, outsideYet, ductYet, gun);

              break;

            case '2':
              insideDuct(breakFoot, outsideYet, ductYet, gun);

              break;

            case '3':
              cout << "You come in for a closer look and a large hairy ";
              cout << "rat jumps out and bites your face." << endl << endl;

              // .C.
              Sleep(5000);

              cout << "You swing out, connecting with the rat's head, ";
              cout << "managing to render it unconscious. Now that that ";
              cout << "obstacle has been overcome, you decide that you will ";
              cout << "continue crawling down the duct." << endl << endl;

              // .C.
              Sleep(8000);

              cout << "A minute later, you begin to feel an increase in your ";
              cout << "heart rate. You pass it off as just a tension, and ";
              cout << "continue on." << endl << endl;

              // .C.
              Sleep (2400);

              cout << "But eventually, the pain grows too large to ignore. ";
              cout << "As you collapse in pain, you realize it is becoming ";
              cout << "increasingly hard to breathe. As the pain throbs hard, ";
              cout << "you cough once. You suddenly realize that the rat did ";
              cout << "in fact triumph over you as you see the foam from your ";
              cout << "mouth pool on the duct floor.";

              startAgain();

              break;

            default:
              // .G.
              defaultCase(3);

              break;

            }
          } while(moveChoice != '1' && moveChoice != '2' && moveChoice != '3');
        }

      else   // If you've been in the duct
        {
        cout << "You start crawling down the duct and pass the dead rat. You ";
        cout << "arrive at the grate, unsure of what you would like to do.";

        // .C.
        Sleep(5000);

        cout << endl << endl << "What would you like to do?" << endl << endl;

        cout << "1 - Open the grate and drop down" << endl;
        cout << "2 - Crawl past the grate" << endl;
        cout << "3 - Go back the way you came" << endl;

        // .D.
        do
          {
          // .E.
          cin >> moveChoice;

          // .F.
          switch (moveChoice)
            {
            case '1':
              // .H.
              if (breakFoot == false)
                {
                cout << "You drop down into semi-darkness. The only light ";
                cout << "source is the red light, so you decide to move in ";
                cout << "that direction." << endl << endl;
                }
              // .H.
              else
                {
                cout << "You drop down, falling on the side of your good ";
                cout << "foot, breaking it. In the semi-darkness, you can ";
                cout << "only see the one red light source." << endl << endl;
                }

              stairs(breakFoot, gun);

              break;

            case '2':
              cout << "You crawl out of the red light and into the darkness. ";
              cout << "Suddenly your weight-bearing hand misses the metal ";
              cout << "duct, coming in contact with only air." << endl << endl;

              // .C.
              Sleep(8000);

              cout << "The next thing that you feel is your head striking the ";
              cout << "ground at an odd angle, shattering your spine.";

              startAgain();

              break;

            case '3':
              grates(breakFoot, outsideYet, ductYet, gun);

              break;

            default:
              // .G.
              defaultCase(3);

              break;

            }
          } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3');
        }
      }

    else if (direction == 2)
      {
      cout << "You crawl down the dark duct, turning right a number of times. ";
      cout << "You finally realize that you have been going in circles, and ";
      cout << "decide to turn left at the next possible opportunity." << endl;
      cout << endl;

      // .C.
      Sleep(8000);

      // Sets it up so that it automatically goes left on the next loop
      loopCrawl = true;

      }
    } while(direction != 1);

  }



void stairsDuct(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {
  // .A.
  char moveChoice;

  cout << "You hear a loud shriek of a dying animal. You go in for a ";
  cout << "closer look and find that a bloody pool in which lies a large, ";
  cout << "dead rat." << endl << endl;

  // .C.
  Sleep(5000);

  cout << "Putting out of your mind what could have happened, you continue ";
  cout << "on, arriving at the grate with the red light filtering through.";

  // .C.
  Sleep(5000);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  cout << "1 - Open the grate and drop down" << endl;
  cout << "2 - Crawl past the grate" << endl;
  cout << "3 - Go back the way you came" << endl;

  // .D.
  do
    {
    // .E.
    cin >> moveChoice;

    // .F.
    switch (moveChoice)
      {
      case '1':
        // .H.
        if (breakFoot == false)
          {
          cout << "You drop down into semi-darkness. The only light ";
          cout << "source is the red light, so you decide to move in ";
          cout << "that direction." << endl << endl;
          }

        // .H.
        else
          {
          cout << "You drop down, falling on the side of your good ";
          cout << "foot, breaking it. In the semi-darkness, you can ";
          cout << "only see the one red light source." << endl << endl;
          }

        // .C.
        Sleep(8000);

        stairs(breakFoot, false);

        break;

      case '2':
        cout << "You crawl out of the red light and into the darkness. ";
        cout << "Suddenly your weight-bearing hand misses the metal duct, ";
        cout << "coming in contact with only air." << endl << endl;

        // .C.
        Sleep(8000);

        cout << "The next thing that you feel is your head striking the ";
        cout << "ground at an odd angle, shattering your spine.";

        startAgain();

        break;

      case '3':
        grates(breakFoot, outsideYet, true, gun);

        break;

      default:
        // .G.
        defaultCase(3);

        break;

      }
    } while(moveChoice != '1' && moveChoice != '2' && moveChoice != '3');

  }



void basementLeave(bool breakFoot, bool outsideYet, bool ductYet, bool gun)
  {
  // .A.
  char moveChoice;

  cout << "You decide to focus on getting out of the room.";

  // .C.
  Sleep(5000);

  cout << endl << endl << "What would you like to do?" << endl << endl;

  // .H.
  if (breakFoot == false)
    {
    cout << "1 - Make a run for it" << endl;
    cout << "2 - Rush the guards with your pin" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          cellphoneCall (3, breakFoot, ductYet, gun);
          break;

        case '2':
          fightGuards(1, breakFoot, ductYet, gun);
          break;

        default:
          // .G.
          defaultCase(2);
          break;
        }
      } while (moveChoice != '1' && moveChoice != '2');
    }

  // .H.
  else                                 // If your foot is broken
    {
    cout << "1 - Attempt a hopping escape" << endl;
    cout << "2 - Attempt a hopping attack" << endl;

    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          cellphoneCall(2, breakFoot, ductYet, gun);

          break;

        case '2':
          fightGuards(1, breakFoot, ductYet, gun);

          break;

        default:
          // .G.
          defaultCase(2);

          break;
        }
      } while (moveChoice != '1' && moveChoice != '2');
    }

  }

void fightGuards(int iteration, bool breakFoot, bool ductYet, bool gun)
  {
  // .A.
  char moveChoice;

  // If you try to rush the two guards outside your room
  if (iteration == 1)
    {
    // .H.
    if (breakFoot == false)
      {
      cout << "You rush the guards, yelling a Vietnamese war cry you ";
      cout << "learned last year. The guards whip around quickly, but ";
      cout << "not before you stick the left guard in the neck with the pin. ";
      cout << "He goes down hard, clutching the area now spewing ";
      cout << "blood." << endl << endl;

      // .C.
      Sleep(11000);

      cout << "You wrench the pin out of the guard's neck and whip around ";
      cout << "just in time to catch the butt of the second guard's M16 right ";
      cout << "in your face." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "You fall down, but are only slightly dazed. The guard is still ";
      cout << "off balance from the impact, so you sweep out his leg, making ";
      cout << "him fall." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "You grab the other guard's gun, aiming it directly ";
      cout << "between the threatening guard's eyes.";

      // .C.
      Sleep(5000);

      cout << endl << endl << "What would you like to do?" << endl << endl;

      cout << "1 - Get rid of the guard for good and" << endl;
      cout << "continue down the hallway" << endl;
      cout << "2 - Get rid of the guard for good and" << endl;
      cout << "go back into the holding room" << endl;
      cout << "3 - Just make sure the guard's unconscious" << endl;
      cout << "and continue down the hallway" << endl;
      cout << "4 - Just make sure the guard's unconscious" << endl;
      cout << "and go back into the holding room" << endl;

      // .D.
      do
        {
        // .E.
        cin >> moveChoice;

        // .F.
        switch (moveChoice)
          {
          case '1':
            hallwayEscape(true, true, ductYet, breakFoot, true);

            break;

          case '2':
            hallwayEscape(true, false, ductYet, breakFoot, true);

            break;

          case '3':
            hallwayEscape(false, true, ductYet, breakFoot, true);

            break;

          case '4':
            hallwayEscape(false, false, ductYet, breakFoot, true);

            break;

          default:
            // .G.
            defaultCase(4);
            break;
          }
        } while (moveChoice != '1' && moveChoice != '2' && moveChoice != '3' &&
        moveChoice != '4');
      }

    // .H.
    else                        // If your foot is broken
      {
      cout << endl << "You crouch to build up your energy in your good ";
      cout << "leg, and then hopping, bound over to the guards." << endl;
      cout << endl;

      // .C.
      Sleep(5000);

      cout << "Luckily, they don't notice you until you're close enough to ";
      cout << "stick one of them with the pin. You hit him in the neck, and ";
      cout << "he clutches the area now spewing blood." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "The other guard is too quick, though, and kicks out your ";
      cout << "good leg's knee, breaking it. You fall to the ground, the ";
      cout << "guard's M16 trained on you the whole time." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "You pick up the fallen pin, and are about to make a last ";
      cout << "attempt to escape when flying lead from the guard's rifle hits ";
      cout << "your chest, puffs of blood filling the air.";

      startAgain();
      }
    }

  // If you try to attack your three captors
  else if (iteration == 2)
    {

    // .H.
    if (breakFoot == false)
      {
      cout << "You lunge at one of the guards with your pin, getting out of ";
      cout << "one of the others' grip. You don't quite make it, and end up ";
      cout << "stumbling to the ground." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "Getting up, you whip around and kick the guard that was ";
      cout << "holding you before, knocking him down. Seeing that he's ";
      cout << "slightly dazed, you lunge at him, attempting to recover his ";
      cout << "gun." << endl << endl;

      // .C.
      Sleep(11000);

      cout << "Just as your fingers feel the hard molded plastic, your back ";
      cout << "feels the impact of well-aimed pieces of lead from the muzzle ";
      cout << "of another guard's rifle's barrel.";

      startAgain();

      }

    // .H.
    else
      {
      cout << "You try lunging at one of the guards with your pin using your ";
      cout << "good leg, but before you even can get to one, the guard behind ";
      cout << "you places a swift kick to the back of your knee, causing you ";
      cout << "to collapse." << endl << endl;

      // .C.
      Sleep(11000);

      cout << "You go down hard, hurting the knee upon impact. This doesn't ";
      cout << "deter you, though - you kick at the attacking guard as the ";
      cout << "others are turning around, managing to knock him down. His gun ";
      cout << "skitters away from him." << endl << endl;

      // .C.
      Sleep(11000);

      cout << "As two still-standing guards now have their M16s aimed at ";
      cout << "your head, doubts start swirling in your mind." << endl << endl;

      // .C.
      Sleep(5000);

      cout << "You put them down and roll to grab the gun. You are about to ";
      cout << "turn on the ground when you hear a burst of fire from behind ";
      cout << "you." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "The blood from the gaping hole in your back floods onto the ";
      cout << "ground, spreading out. In the last minutes of your ebbing ";
      cout << "life, you consider the possibility that you made the wrong ";
      cout << "decision.";

      startAgain();
      }

    }

  }


void peppersprayEscape(bool breakFoot, bool gun)
  {
  // Is the guard dead? (only necessary for this function)
  bool guardDead = false;

  // .A.
  char moveChoice;

  // .H.
  if (breakFoot == false)
    {
    cout << "You grab at the pepperspray on the guard's belt, but it seems to ";
    cout << "clipped on. The guard has already realized your efforts, so you ";
    cout << "know that you don't have the required time to unclip it." << endl;
    cout << endl;

    // .C.
    Sleep(9500);

    cout << "Instead, you turn the can upwards and spray the guard in the ";
    cout << "face. Losing his sense of perception, he falls down. You turn ";
    cout << "around just in time to catch a kick to the chest from another of ";
    cout << "the guards, sending you sprawling into the guard on the floor. ";
    cout << endl << endl;

    // .C.
    Sleep(11000);

    cout << "You turn over, holding your stomach with one hand, making it ";
    cout << "appear as if you're hurt. With your other hand you slowly unclip ";
    cout << "the pepperspray, making sure you don't make much sound." << endl;
    cout << endl;

    // .C.
    Sleep(9500);

    cout << "After it's unclipped, you whip around, the spray catching the ";
    cout << "second guard straight in the face. You make your move to the ";
    cout << "third as he falls." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "The last guard is a bit farther away, and has a gun trained on ";
    cout << "you. You raise your hands above your head in surrender, ";
    cout << "crouching to put the cannister on the floor." << endl << endl;

    // .C.
    Sleep(9500);

    cout << "On the way back up, though, you lunge at him in a tackling ";
    cout << "position. He is so surprised at the sudden action that he isn't ";
    cout << "even able to squeeze off a few rounds before your shoulder hits ";
    cout << "his upper leg." << endl << endl;

    // .C.
    Sleep(11000);

    cout << "Your momentum transfers to him, knocking the air out of his lungs ";
    cout << "with a grunt of pain. As he slides across the floor, you both ";
    cout << "struggle for control of his gun." << endl << endl;

    // .C.
    Sleep(9500);

    cout << "The struggle finally results in your possession. You stand up, ";
    cout << "keeping a bead on his head, and try to decide your next move. ";

    // .C.
    Sleep(5500);

    cout << endl << endl << "What would you like to do?" << endl << endl;

    cout << "1 - Get rid of the guard for good and" << endl;
    cout << "continue down the hallway" << endl;
    cout << "2 - Get rid of the guard for good and" << endl;
    cout << "go down one of the side halls" << endl;
    cout << "3 - Just make sure the guard's unconscious" << endl;
    cout << "and continue down the hallway" << endl;
    cout << "4 - Just make sure the guard's unconscious" << endl;
    cout << "and go down one of the side halls" << endl;


    // .D.
    do
      {
      // .E.
      cin >> moveChoice;

      // .F.
      switch (moveChoice)
        {
        case '1':
          // If the guard isn't dead yet...
          if (guardDead == false)
            {
            cout << "Bullets from your rifle slam into the guard's forehead, ";
            cout << "splashing blood on his face." << endl;

            cout << "You continue walking forward, and eventually come up to ";
            cout << "another hallway to the left with a red light at the end.";

            //... make him dead
            guardDead = true;

            }

          // If the guard is dead
          else
            {
            cout << "You already incapacitated the guard far behind you now, ";
            cout << "and so now just continue forward. Eventually, you again ";
            cout << "come up to a hallway to the left with the red light at ";
            cout << "the end.";
            }

          cout << endl << "Try Again:" << endl;

          break;


        case '2':
          // If the guard isn't dead yet...
          if (guardDead == false)
            {
            cout << "Rounds from your rifle tear into the guard's soft flesh, ";
            cout << "causing massive damage. Y";

            //... make him dead
            guardDead = true;
            }

          // If the guard is dead
          else
            {
            cout << "You already incapacitated the guard far behind you, so y";
            }

          cout << "ou start towards the dim red light, seeing it as your ";
          cout << "only option." << endl;

          stairs(breakFoot, true);

          break;


        case '3':
          // If the guard isn't dead yet
          if (guardDead == false)
            {
            cout << "Turning your M16 around, you smash it into the ";
            cout << "remaining guard's forehead. ";
            }

          // If the guard is dead
          else
            {
            cout << "You already incapacitated the guard far behind you. ";
            }

          cout << "You continue walking forward, and eventually come up to ";
          cout << "another hallway to the left with a red light at the end.";

          cout << endl << "Try Again:" << endl;

          break;


        case '4':
          // If the guard isn't dead
          if (guardDead == false)
            {
            cout << "Turning the M16 around, you smash the butt into the ";
            cout << "remaining guard's forehead. Y";
            }

          // If the guard is dead
          else
            {
            cout << "The guard far behind you now is already incapacitated, ";
            cout << "so y";
            }

          cout << "ou start towards the dim red light, seeing it as your ";
          cout << "only option." << endl << endl;

          stairs(breakFoot, true);


          break;

        default:
          // .G.
          defaultCase(4);

          break;
        }
      } while (moveChoice != '2' && moveChoice != '4');

    }

  // .H.
  else
    {
    cout << "You grab at the pepperspray on the guard's belt, but it proves ";
    cout << "to be clipped on. You know you don't have time to work at the ";
    cout << "clip, so instead, you turn it up towards the guard's face, ";
    cout << "pulling his head down to it at the same moment." << endl << endl;

    // .C.
    Sleep(9000);

    cout << "Only one of the two other guards notices what you've done, but ";
    cout << "acts accordingly. The kick hits you square in the back, sending ";
    cout << "you sprawling." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "You hunch over the pepperspray still clipped to the writhing ";
    cout << "guard, unclipping it slowly as to make it less evident. You then ";
    cout << "You then whip around, spraying it directly into the second ";
    cout << "guard's face." << endl << endl;

    // .C.
    Sleep(9000);

    cout << "The only problem that you can see now is the last guard, who ";
    cout << "seems very far away. You hop at him as quickly as you can, but ";
    cout << "proves to be not fast enough." << endl << endl;

    // .C.
    Sleep(9500);

    cout << "The cartilage, bone, and muscle of your ribcage is ripped up as ";
    cout << "the bullets tear through. The gunfire only stopps once you have ";
    cout << "hit the ground and are spurting blood. You think you might have ";
    cout << "made the wrong decision as you lose consciousness.";

    startAgain();

    }
  }



void sidehallRun(bool breakFoot, bool gun)
  {
  // .H.
  if (breakFoot == false)
    {
    cout << "Wrenching yourselves from your captors' grips, you run down one ";
    cout << "of the side halls. Yelling at you, they run after you, hard on ";
    cout << "your tail." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "You might outrun them for now, but you do eventually ";
    cout << "want them off your tail. You skid to a stop, turning sideways. ";
    cout << "Before you realize what they've done, you perform a brilliant ";
    cout << "side kick to one of the guard's throats. Working just as a ";
    cout << "clothesline would, the guard is on his back in seconds." << endl;
    cout << endl;

    // .C.
    Sleep(11000);

    cout << "The other guards run up just in time for you to grab the ";
    cout << "incapacitated guard's rifle and have it pointed. You squeeze off ";
    cout << "a couple rounds at the left guard, rolling to avoid the gunfire ";
    cout << "from the one on the right." << endl << endl;

    // .C.
    Sleep(9800);

    cout << "As you right yourself again, you aim and shoot, knocking the ";
    cout << "final guard backwards." << endl << endl;

    // .C.
    Sleep(5000);

    cout << "With all the guards vanquished, you start walking towards a red ";
    cout << "light at the end of the hallway." << endl << endl;

    // .C.
    Sleep(5000);

    stairs(breakFoot, true);

    }

  // .H.
  else
    {
    cout << "You wrench yourself free of your captors' grips and start ";
    cout << "hopping down the hall. As you expected, they give chase." << endl;
    cout << endl;


    // .C.
    Sleep(5000);

    cout << "Even though you have a head start, they are much faster. As they ";
    cout << "near you, now close enough to grab you, you feign a fall. Once ";
    cout << "you're on the ground, using your bad leg to pivot, you kick out ";
    cout << "the closest guard's legs." << endl << endl;

    // .C.
    Sleep(9500);

    cout << "As he falls, you grab him and his gun. Keeping him in a ";
    cout << "you keep the gun trained on the other guards." << endl << endl;

    // .C.
    Sleep(5200);

    cout << "You realize too late that the guard that you are holding isnt' ";
    cout << "quite as incapacitated as you thought. His foot impacts bone, ";
    cout << "splintering your only good leg's fibula." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "Wincing against the massive pain, you use broken foot to kick ";
    cout << "the attacking guard in the back. As your foot travels through ";
    cout << "the air toward one of your captors, though, bullets also travel ";
    cout << "from your other captors at you. Blood puffs appearing over your ";
    cout << "chest, your internal organs are ripped apart by the hot lead.";

    // .C.
    Sleep(1200);

    startAgain();

    }

  }



void hallwayEscape(bool killGuard, bool hallway, bool ductYet, bool breakFoot,
bool gun)
  {
  // .A.
  char moveChoice;

  // If you choose to only render the guard unconscious
  if (killGuard == false)
    {
    cout << "You turn the M16 around and jab the guard in the face with the ";
    cout << "butt, rendering him unconscious." << endl << endl;

    // .C.
    Sleep(5000);

    // If you choose not to go further down the hallway
    if (hallway == false)
      grates(breakFoot, true, ductYet, gun);

    // If you choose to go further down the hallway
    else
      {
      cout << "Deciding to continue down the hallway, you cautiously move ";
      cout << "away from the two bodies on the ground into greater darkness. ";
      cout << endl << endl;

      // .C.
      Sleep(6000);

      cout << "Your eyes eventually focus again, and you can see an ";
      cout << "intersection up ahead. There is a guard standing near the left ";
      cout << "wall and he hasn't heard you yet." << endl << endl;

      // .C.
      Sleep(8000);

      cout << "You think of your options, and decide on rushing him, as it ";
      cout << "would be the least expected." << endl << endl;

      // .C.
      Sleep(6000);

      cout << "You run at him, concentrating on being as silent as possible ";
      cout << "until the last second. The guard finally notices you, and ";
      cout << "raises his weapon despite you having yours aimed at him. You ";
      cout << "fire a short burst, and the guard is slumps to the ";
      cout << "floor." << endl << endl;

      // .C.
      Sleep(11000);

      cout << "You take his weapon and try to decide which way you want to ";
      cout << "go. To the left, there is a red light in the distance, ";
      cout << "and in front of you , there is only more darkness.";

      // .C.
      Sleep(9500);

      cout << endl << endl << "What would you like to do?" << endl << endl;

      cout << "1 - Continue forward" << endl;
      cout << "2 - Go towards the red light on your left" << endl;

      // .D.
      do
        {
        // .E.
        cin >> moveChoice;

        // .F.
        switch (moveChoice)
          {
          case '1':
            cout << "You continue walking forward, and eventually come up to ";
            cout << "another hallway to the left with a red light at the end. ";
            cout << "You could continue forward again, or go towards the red ";
            cout << "light." << endl;
            cout << "Try Again:" << endl;

            break;

          case '2':
            stairs(breakFoot, true);

            break;

          default:
            // .G.
            defaultCase(2);

            break;
          }
        } while (moveChoice != '1' && moveChoice != '2');

      }
    }

  // If you choose to kill the guard
  else
    {
    cout << "The fast-moving projectiles from your gun slam into the guard's ";
    cout << "forehead, splashing his face with blood." << endl << endl;

    // .C.
    Sleep(5000);

    // If you choose not to go further down the hallway
    if (hallway == false)
      grates(breakFoot, true, ductYet, gun);

    // If you choose to go further down the hallway
    else
      {
      cout << "Deciding to continue down the hallway, you cautiously move ";
      cout << "away from the two bodies on the ground into greater darkness. ";
      cout << endl << endl;

      // .C.
      Sleep(6000);

      cout << "Your eyes eventually focus again, and you can see an ";
      cout << "intersection up ahead. There is a guard standing near the left ";
      cout << "wall and he hasn't heard you yet." << endl << endl;

      // .C.
      Sleep(5000);

      cout << "You think of your options, and decide on rushing him, as it ";
      cout << "would be the least expected." << endl << endl;

      // .C.
      Sleep(5000);

      cout << "You run at him, concentrating on being as silent as possible ";
      cout << "until the last second. The guard finally notices you, and ";
      cout << "raises his weapon despite you having yours aimed at him. You ";
      cout << "fire a short burst, and the guard is slumps to the ";
      cout << "floor." << endl << endl;

      // .C.
      Sleep(10500);

      cout << "You take his weapon and try to decide which way you ";
      cout << "want to go. To the left, there is a red light in the distance, ";
      cout << "and in front of you , there is only more darkness.";

      // .C.
      Sleep(5000);

      cout << endl << endl << "What would you like to do?" << endl << endl;

      cout << "1 - Continue forward" << endl;
      cout << "2 - Go towards the red light on your left" << endl;

      // .D.
      do
        {
        // .E.
        cin >> moveChoice;

        // .F.
        switch (moveChoice)
          {
          case '1':
            cout << "You continue walking forward, and eventually come up to ";
            cout << "another hallway to the left with a red light at the end. ";
            cout << "You could continue forward again, or go towards the red ";
            cout << "light." << endl;
            cout << "Try Again:" << endl;

            break;

          case '2':
            stairs(breakFoot, true);

            break;

          default:
            // .G.
            defaultCase(2);

            break;
          }
        } while (moveChoice != '1' && moveChoice != '2');
      }
    }
  }


void stairs(bool breakFoot, bool gun)
  {
  // If you have a gun
  if (gun == true)
    {
    cout << "As you cautiously move more and more into the red light, you ";
    cout << "start to make out a set of stairs. You step up and continue ";
    cout << "moving forward." << endl << endl;

    // .C.
    Sleep(8000);

    cout << "Once you hit the first landing, a strange calm overcomes you. ";
    cout << "you have made it this far, overcoming a lot, including defending ";
    cout << "guards. You feel that anything else that comes your way can also ";
    cout << "be overcome.";

    startAgain();
    }

  // If your foot's broken
  if (breakFoot == true)
    {
    cout << "As you crawl more and more into the red light, you start to make ";
    cout << "out horizontal shadows at eye level. As you get closer, you come ";
    cout << "to realize that they are a set of stairs. You coninue on, ";
    cout << "dragging yourself up the stairs in pain." << endl << endl;

    // .C.
    Sleep(10000);

    cout << "A strange calm overcomes you, though, as you reach the first ";
    cout << "landing. You have made it this far, overcoming a lot, including ";
    cout << "a broken foot. You think that anything else that comes your way ";
    cout << "can also be overcome.";

    startAgain();
    }

  // If your foot's not broken and if you don't have a gun
  if (breakFoot == false && gun == false)
    {
    cout << "The red light swims closer and closer to you as you cautiously ";
    cout << "move towards it. You start to make out some horizontal shadows ";
    cout << "which you come to realize are stairs. You decide to continue on ";
    cout << "up the stairs." << endl << endl;

    // .C.
    Sleep(10000);

    cout << "As you reach the landing, you feel a strange calm overcoming ";
    cout << "you. You have made it this far, overcoming many obstacles, ";
    cout << "including a seemingly inescapable safe. You feel that anything ";
    cout << "else that comes your way can also be overcome.";

    startAgain();
    }
  }








//------------------------------------------------------------------------------
// Used-over-and-over smaller functions
//------------------------------------------------------------------------------




void startAgain()
  {
  // The variable for your choice of
  char tryAgain;

  // .C.
  Sleep(10000);

  cout << endl << endl << "Would you like to try again? (Y/N)" << endl;

  // .D.
  do
    {
    // .E.
    cin >> tryAgain;

    // .F.
    if (tryAgain == 89 || tryAgain == 121)
      {
      system ("cls");
      init();
      }

    // .F.
    else if (tryAgain == 78 || tryAgain == 110)
      cout << "                                    GAME OVER" << endl;

    // .F.
    else cout << "Please use Y or N" << endl;

    } while (tryAgain != 78 && tryAgain != 89 && tryAgain != 121 &&
    tryAgain != 110);
  }


void spacer(int size)
  {
  // Centers text
  for(int i = (48 - size); i > 0 ; i--)
    cout << " ";
  }


void defaultCase(int maximum)
  {
  cout << "Choose a number between 1 and " << maximum << "." << endl;
  }
