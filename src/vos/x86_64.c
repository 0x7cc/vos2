//
// Created by x7cc on 2020/4/26.
//

#include "vos/x86_64.h"
#include "vos/memory.h"
#include "vos/vos.h"

void* make_guest_PML4E ()
{
  uint64 page_begin = 0;

  uint64* pml4 = (uint64*)calloc (VOS_PAGE_SIZE);
  for (int L2 = 0; L2 < 1; ++L2)
  {
    uint64* pbp = (uint64*)calloc (VOS_PAGE_SIZE);
    pml4[L2]    = (uint64)pbp | 1;
    for (int L3 = 0; L3 < 1; ++L3)
    {
      uint64* pb = (uint64*)calloc (VOS_PAGE_SIZE);
      pbp[L3]    = (uint64)pb | 1;

      for (int L4 = 0; L4 < 512; ++L4)
      {
        uint64* pt = (uint64*)calloc (VOS_PAGE_SIZE);
        for (int i = 0; i < 512; ++i)
        {
          ((uint64*)pt)[i] = page_begin | 1;
          page_begin += VOS_PAGE_SIZE;
        }
        pb[L4] = (uint64)pt | 1;
      }
    }
  }
  return pml4;
}