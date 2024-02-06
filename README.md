A simple 3D Vector class that can be modified further for specific use

Constructors: 

	VectorClass () -> Creates a zero vector.
	VectorClass (double xValue, double yValue, double zValue) -> Creates a vector with specific x, y and z coordinates.
 
Methods:

  Getters (returns a specific component of the vector): 
  
    double getX ()
    double getY ()
    double getZ ()

  Setters (adjust a specific component of the vector):
  
    void setX (double xValue)
    void setY (double yValue)
    void setZ (double zValue)

  Operations:
  
    Adding: 
    
	    VectorClass operator+ (const VectorClass& otherVector) -> You can add 2 vectors using '+'
	    VectorClass add (const VectorClass& otherVector)
     
    Subtracting:
    
	    VectorClass operator- (const VectorClass& otherVector) -> You can subtract 2 vectors using '-'
	    VectorClass subtract (const VectorClass& otherVector)

     Multiplying: 
     
	    VectorClass operator* (const double scalarValue)  -> You can multiply 2 vectors using '*'
	    VectorClass multiply (const double scalarValue)

     Dividing:

	    VectorClass operator/ (const double scalarValue)  -> You can divide 2 vectors using '/'
	    VectorClass divide (const double scalarValue)
     
     Misc:
    
	    double Modulus () -> Finds the length of the vector.

	Console Logging:
 
	  EnableVectorClassLogMessages () -> enable console logging
	  DisableVectorClassLogMessages () -> disable console logging

 	Vector printing function 
   operator<< (std::ostream& stream, const VectorClass& vector); -> Enables vector coordinate printing functionality with std::cout and '<<'
