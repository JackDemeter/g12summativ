

//giving row and column a corresopnding arduino pin.
int row1 = 10, row2 = A1, row3 = 12, row4 = A2, row5 = 5, row6 = 13, row7 = 3, row8 = 8;   

int col1 = A3, col2 = 2, col3 = 6, col4 = 11, col5 = 7, col6 = 9, col7 = A0, col8 = 4;   

//arrays that contain all the rows or columns in the actual order, as the pins on the 8x8 matrix are not in a logical order
int rows[8] = {row1,row2,row3,row4,row5,row6,row7,row8};

int cols[8] = {col1,col2,col3,col4,col5,col6,col7,col8};

//test pins that will determine where and what animations will occur
//these pins are high values because our non test values will be analog reads, which will be divided to create values from 
//0-7 to correspond with the row or column
int type = 200;                   //this determines the type of animation

//posX and posY create a coordinate system,the location will be refered to as "origin"
int posX = 400;                   //this determines the x position(row) of an origin of the animation
int posY = 200;                   //this determines the y position(column) of an origin of the animation
  
//control pins (that decide what animation will be created) 
//These values change the array
int control = A5;

char slaveLetter = 'B';




//this array corresponds to our matrix, any value turned high will be high on the matrix
int matrix[8][8] = 
{
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};






//////////////////////// Functions ///////////////////////////////////


//can either clear our array or turn all of it on
void fillArray(int matrix[8][8], int value)
{
  for (int i = 0; i < 8; i++)
  {
    for (int n = 0; n < 8; n++)
    {
      matrix[i][n] = value;
    }
  }  
}

//makes a dot on the matrix a value of 1 or 0 so it becomes on or off
void dot(int matrix[8][8], int posX, int posY, int value)
{
  matrix[posY][posX] = value;  
}

//an animation that creates a cross based on where the origin is
void cross(int matrix[8][8], int posX, int posY, int value)
{
  for (int i = 0; i < 8; i++)
  {
    matrix[i][posX] = value;
    matrix[posY][i] = value;
  }
}


void setup(){
 
  
  
  //set matrix pins to outputs, control pins to inputs
  
  //matrix pins
  for (int i=0;i<8;i++){
    pinMode(rows[i],OUTPUT);
  }
  for (int i=0;i<8;i++){
    pinMode(cols[i],OUTPUT);
  }
    
  //control pins
  pinMode(control,INPUT); 
  Serial.begin(9600);
}

//lights up our matrix based on the matrix array
void matrixToDisplay(int list[8][8]) 
{
  //first we must turn everything low
    for (int i = 0; i < 8 ; i++){
      for (int x = 0; x < 8 ; x++){
        digitalWrite(cols[x],LOW);
        digitalWrite(rows[x],LOW);
      }
      //actully does the lighting up by going throw the array and giving the 1's power
      digitalWrite(rows[i],HIGH);
      for (int x = 0; x <8 ; x++){
        digitalWrite(cols[x],!(list[i][x]));
      }
      delay(1);
    }
        
}

//---------------------------------------------------------------------THE LOOP-----------------------------------------------------------------------------
  
void loop(){ 
  //these are the actual code that will be used to read values off the other arduino
  if (Serial.available()) slaveLetter = Serial.read();

  Serial.println(slaveLetter);
  
  
  //reads the value of type and performs an animation based off that
  switch (slaveLetter)
  {
    //hard coded to display the letter accessing individual leds
    case 'A':
    {
      fillArray(matrix, 0);
      dot(matrix, 2, 3, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 5, 2, 1);
      dot(matrix, 5, 3, 1);
      dot(matrix, 5, 4, 1);
      dot(matrix, 5, 5, 1);
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 3, 4, 1);
      dot(matrix, 4, 4, 1);
      dot(matrix, 2, 6, 1);
      dot(matrix, 5, 6, 1);
      break;
    }
    case 'B':
    {
      fillArray(matrix, 0);   
        
      dot(matrix, 2, 1, 1);
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 3, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 2, 6, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 3, 3, 1);
      dot(matrix, 3, 6, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 4, 3, 1);
      dot(matrix, 4, 6, 1);
      dot(matrix, 5, 2, 1);
      dot(matrix, 5, 4, 1);
      dot(matrix, 5, 5, 1);
      break;
    }
    case 'C':
    {
      fillArray(matrix, 0);   
        
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 3, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 3, 6, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 4, 6, 1);
      dot(matrix, 5, 2, 1);
      dot(matrix, 5, 5, 1);
      break;
    }
    case 'D':
    {
      fillArray(matrix, 0);   
        
      dot(matrix, 2, 1, 1);
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 3, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 2, 6, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 3, 6, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 4, 6, 1);
      dot(matrix, 5, 2, 1);
      dot(matrix, 5, 3, 1);
      dot(matrix, 5, 4, 1);
      dot(matrix, 5, 5, 1);
      break;
    }
    case 'E':
    {
      fillArray(matrix, 0);   
        
      dot(matrix, 2, 1, 1);
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 3, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 2, 6, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 3, 3, 1);
      dot(matrix, 3, 6, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 4, 3, 1);
      dot(matrix, 4, 6, 1);
      dot(matrix, 5, 1, 1);
      dot(matrix, 5, 3, 1);
      dot(matrix, 5, 6, 1);
      break;
    }
    case 'F':
    {
      fillArray(matrix, 0);   
        
      dot(matrix, 2, 1, 1);
      dot(matrix, 2, 2, 1);
      dot(matrix, 2, 3, 1);
      dot(matrix, 2, 4, 1);
      dot(matrix, 2, 5, 1);
      dot(matrix, 2, 6, 1);
      dot(matrix, 3, 1, 1);
      dot(matrix, 3, 3, 1);
      dot(matrix, 4, 1, 1);
      dot(matrix, 4, 3, 1);
      dot(matrix, 5, 1, 1);
      dot(matrix, 5, 3, 1);

      break;
    }
    default:
    {
      fillArray(matrix, 0);
      break;
    }
  }
  
  //displays the matrix based off of the matrix array
  matrixToDisplay(matrix);
}



