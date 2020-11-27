#include "vmx.h"
#include "svm.h"
#include "x86_64.h"
#include "vmclient.h"

#include <Library/UefiLib.h>

void boot () {

  vmclient* client = nullptr;
  vmclient_load (&client);

  if (client == nullptr) {
    AsciiPrint ("vmclient load failed.\n");
    goto err;
  }

  AsciiPrint ("vmclient loaded.\n");

err:
  while (1)
    ;
}