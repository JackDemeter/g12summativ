# g12summativ

Project I created in grade 12 with a friend as our tech summative, the project uses an aruduino, 8x8 matrix and flex sensors to convert sign language symbols into letters

### INTRO ###
We looked at the summative as an opportunity to apply what we learned. At first we had no idea what we wanted to do, but we definitely wanted to be creative and develop an innovative, ambitious but also realistic project within the timeline. We both came across the idea of a glove that would utilize bluetooth to move an object. We decided to do a bit of research to collect more data and ideas about our project. This would help us minimize our problems along the way. In the end we chose to create a glove that would control an 8x8 matrix via connections between two arduinos. We began to build the matrix, using a premade 8x8 LED matrix we had to learn about its built in wire configuration. After figuring out the configuration, we began to code it to create animations given an x, y, and type value from the master arduino. To read between the two arduinos we tested multiple designed and settled on using the built in Serial function to communicate between the devices. After testing the slave arduino, we began to create the master arduino and test the communication between them to identify any limitations we might face. Finally, we began building our glove with flex sensors and attached it to our arduino components. Then, we developed code to read data based on the flex sensor values. To finalize the code we fixed small bugs and fine tuned the glove for better reading of the hand gestures.

### FUTURE APPLICATION ###

*POST NOTE*
Initially we intended on connecting this project to a drone and allowing it to be controlled however grade 12 me did not know IMUs existed at the time and the project solely relied on flex resistors

### CODE EXPLANATION ###
Because our project requires two arduinos, we have two sets of code: slave code and master code which communicate to each other using the TX RX ports. 

Master Code:  This code is sent to the arduino by the glove. The code is setup to analogread values based on the flex sensors. The values are then divided by 70 in order to create “easier” numbers (ie. 2,3,4,5,6,7). When a certain combination of values is returned, the code will send a serial write that is a letter to the slave arduino.

Slave Code: This code begins by serial reading the letter that is sent from the master code. This letter is used in a switch statement and based on the letter, a number of dots will be turned on in the matrix in order to create the letter. The letters range from A to F. 

