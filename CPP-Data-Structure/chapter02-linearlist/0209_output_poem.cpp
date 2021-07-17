#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    /* Declare the 2D string array */
    char Str[20][50]={ "Bright star by John Keats",    
                        "================================================",   
                        "Bright star, would I were stedfast as thou art,", 
                        "Not in lone splendour hung aloft the night.", 
                        "And watching, with eternal lids apart,", 
                        "Like nature¡¯s patient, sleepless Eremite.", 
                        " "
                        "The moving waters at their priestlike task,",
                        "Of pure ablution round earth¡¯s human shores.", 
                        "Or gazing on the new soft-fallen mask,", 
                        "Of snow upon the mountains and the moors.", 
                        " ",
                        "No¡ªyet still stedfast, still unchangeable,", 
                        "Pillow¡¯d upon my fair love¡¯s ripening breast.",
                        "To feel for ever its soft fall and swell,", 
                        "Awake for ever in a sweet unrest.", 
                        " ", 
                        "Still, still to hear her tender-taken breath,", 
                        "And so live ever¡ªor else swoon to death." };
    
    int i;
    for (i=0; i<20; i++)
        cout << Str[i] << endl;                  
        
    return 0;
}

/* Output */

/* 
Bright star by John Keats
================================================
Bright star, would I were stedfast as thou art,
Not in lone splendour hung aloft the night.
And watching, with eternal lids apart,
Like nature¡¯s patient, sleepless Eremite.

The moving waters at their priestlike task,
Of pure ablution round earth¡¯s human shores.
Or gazing on the new soft-fallen mask,
Of snow upon the mountains and the moors.

No¡ªyet still stedfast, still unchangeable,
Pillow¡¯d upon my fair love¡¯s ripening breast.
To feel for ever its soft fall and swell,
Awake for ever in a sweet unrest.

Still, still to hear her tender-taken breath,
And so live ever¡ªor else swoon to death.
 */