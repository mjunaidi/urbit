/* j/5/lore.c
**
** This file is in the public domain.
*/
#include "all.h"


  u2_noun
  u2_cqe_lore(u2_atom lub)
  {
    c3_w    len_w = u2_cr_met(3, lub);
    c3_w    pos_w = 0;
    u2_noun tez = u2_nul;

    while ( 1 ) {
      c3_w meg_w;

      if ( pos_w >= len_w ) {
        return u2_ckb_flop(tez);
      } else {
        meg_w = 0;

	c3_y byt_y;
        while ( 1 ) {
          byt_y = u2_cr_byte(pos_w + meg_w, lub);

          if ( (10 == byt_y) || (0 == byt_y) ) {
            break;
          } else meg_w++;
        }

        if ((byt_y == 0) && ((pos_w + meg_w + 1) < len_w)) {
	  return u2_cm_bail(c3__exit);
	}

        {
          c3_y* byts_y = alloca(meg_w);

          u2_cr_bytes(pos_w, meg_w, byts_y, lub);
          tez = u2nc(u2_ci_bytes(meg_w, byts_y), tez);
          pos_w += (meg_w + 1);
        }
      }
    }
  }

  u2_noun
  u2_cwe_lore(u2_noun cor)
  {
    u2_noun lub;

    if ( (u2_none == (lub = u2_cr_at(u2_cv_sam, cor))) ||
         (u2_no == u2ud(lub)) )
    {
      return u2_cm_bail(c3__fail);
    } else {
      return u2_cqe_lore(lub);
    }
  }