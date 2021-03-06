/**
 * Generates a repeatable random bitmap.
 * 
 * Written by Andras Majdan
 * License: GNU General Public License Version 3
 * 
 * Report bugs to <majdan.andras@gmail.com>
 */

#include "rrr-sdsl.hpp"

namespace rrr_size {
	
  std::string rrr_sdsl::get_name() {
    return "sdsl";
  }
	  
  void rrr_sdsl::load_file(std::string filename, long len) {
	FILE *fileh;
    unsigned char ch; 
	int ci;
	sdsl::bit_vector bv;
	
    bv = sdsl::bit_vector(len*8);
    fileh = fopen(filename.c_str(), "r");

    ci = 0;
    while(fread(&ch, sizeof(unsigned char), 1, fileh) == 1)
    {
	  for(int i=0; i<8; i++)
        bv[ci*8 + i] = ch & (unsigned char)(1<<i);
	  ++ci;
    }

    if(!feof(fileh))
	  throw string("Error: I/O");

    fclose(fileh);

    rv = new sdsl::rrr_vector<BLOCK>(bv);
  }
	  
  long rrr_sdsl::get_size() {
	return rv->get_rrr_size();
  }
	  
  void rrr_sdsl::free_memory() {
    delete rv;
  }

}
