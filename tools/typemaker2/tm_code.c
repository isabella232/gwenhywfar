/**********************************************************
 * This file has been automatically created by "typemaker2"
 * from the file "tm_code.xml".
 * Please do not edit this file, all changes will be lost.
 * Better edit the mentioned source file instead.
 **********************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "tm_code_p.h"

#include <gwenhywfar/misc.h>
#include <gwenhywfar/debug.h>

/* code headers */

/* macro functions */
GWEN_LIST_FUNCTIONS(TYPEMAKER2_CODE, Typemaker2_Code)


TYPEMAKER2_CODE *Typemaker2_Code_new() {
  TYPEMAKER2_CODE *p_struct;

  GWEN_NEW_OBJECT(TYPEMAKER2_CODE, p_struct)
  GWEN_LIST_INIT(TYPEMAKER2_CODE, p_struct)
  /* members */
  p_struct->id=NULL;
  p_struct->memberFlagsMask=NULL;
  p_struct->memberFlagsValue=NULL;
  p_struct->code=NULL;
  p_struct->memberFlagsMaskInt=0;
  p_struct->memberFlagsValueInt=0;

  return p_struct;
}

void Typemaker2_Code_free(TYPEMAKER2_CODE *p_struct) {
  if (p_struct) {
    GWEN_LIST_FINI(TYPEMAKER2_CODE, p_struct)
  /* members */
    free(p_struct->id);
    free(p_struct->memberFlagsMask);
    free(p_struct->memberFlagsValue);
    free(p_struct->code);
    
    
    GWEN_FREE_OBJECT(p_struct);
  }
}

TYPEMAKER2_CODE *Typemaker2_Code_dup(const TYPEMAKER2_CODE *p_src) {
  TYPEMAKER2_CODE *p_struct;

  assert(p_src);
  p_struct=Typemaker2_Code_new();
  /* member "id" */
  if (p_struct->id) {
    free(p_struct->id);
    p_struct->id=NULL;
  }
  if (p_src->id) {
    p_struct->id=strdup(p_src->id);
  }

  /* member "memberFlagsMask" */
  if (p_struct->memberFlagsMask) {
    free(p_struct->memberFlagsMask);
    p_struct->memberFlagsMask=NULL;
  }
  if (p_src->memberFlagsMask) {
    p_struct->memberFlagsMask=strdup(p_src->memberFlagsMask);
  }

  /* member "memberFlagsValue" */
  if (p_struct->memberFlagsValue) {
    free(p_struct->memberFlagsValue);
    p_struct->memberFlagsValue=NULL;
  }
  if (p_src->memberFlagsValue) {
    p_struct->memberFlagsValue=strdup(p_src->memberFlagsValue);
  }

  /* member "code" */
  if (p_struct->code) {
    free(p_struct->code);
    p_struct->code=NULL;
  }
  if (p_src->code) {
    p_struct->code=strdup(p_src->code);
  }

  /* member "memberFlagsMaskInt" */
  p_struct->memberFlagsMaskInt=p_src->memberFlagsMaskInt;

  /* member "memberFlagsValueInt" */
  p_struct->memberFlagsValueInt=p_src->memberFlagsValueInt;

  return p_struct;
}

const char *Typemaker2_Code_GetId(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->id;
}

const char *Typemaker2_Code_GetMemberFlagsMask(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->memberFlagsMask;
}

const char *Typemaker2_Code_GetMemberFlagsValue(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->memberFlagsValue;
}

const char *Typemaker2_Code_GetCode(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->code;
}

uint32_t Typemaker2_Code_GetMemberFlagsMaskInt(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->memberFlagsMaskInt;
}

uint32_t Typemaker2_Code_GetMemberFlagsValueInt(const TYPEMAKER2_CODE *p_struct) {
  assert(p_struct);
  return p_struct->memberFlagsValueInt;
}

void Typemaker2_Code_SetId(TYPEMAKER2_CODE *p_struct, const char *p_src) {
  assert(p_struct);
  if (p_struct->id) {
    free(p_struct->id);
  }
  if (p_src) {
    p_struct->id=strdup(p_src);
  }
  else {
    p_struct->id=NULL;
  }
}

void Typemaker2_Code_SetMemberFlagsMask(TYPEMAKER2_CODE *p_struct, const char *p_src) {
  assert(p_struct);
  if (p_struct->memberFlagsMask) {
    free(p_struct->memberFlagsMask);
  }
  if (p_src) {
    p_struct->memberFlagsMask=strdup(p_src);
  }
  else {
    p_struct->memberFlagsMask=NULL;
  }
}

void Typemaker2_Code_SetMemberFlagsValue(TYPEMAKER2_CODE *p_struct, const char *p_src) {
  assert(p_struct);
  if (p_struct->memberFlagsValue) {
    free(p_struct->memberFlagsValue);
  }
  if (p_src) {
    p_struct->memberFlagsValue=strdup(p_src);
  }
  else {
    p_struct->memberFlagsValue=NULL;
  }
}

void Typemaker2_Code_SetCode(TYPEMAKER2_CODE *p_struct, const char *p_src) {
  assert(p_struct);
  if (p_struct->code) {
    free(p_struct->code);
  }
  if (p_src) {
    p_struct->code=strdup(p_src);
  }
  else {
    p_struct->code=NULL;
  }
}

void Typemaker2_Code_SetMemberFlagsMaskInt(TYPEMAKER2_CODE *p_struct, uint32_t p_src) {
  assert(p_struct);
  p_struct->memberFlagsMaskInt=p_src;
}

void Typemaker2_Code_SetMemberFlagsValueInt(TYPEMAKER2_CODE *p_struct, uint32_t p_src) {
  assert(p_struct);
  p_struct->memberFlagsValueInt=p_src;
}

void Typemaker2_Code_ReadXml(TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db) {
  assert(p_struct);
  /* member "id" */
  if (p_struct->id) {
    free(p_struct->id);
  }
  p_struct->id=NULL;
  { const char *s; s=GWEN_XMLNode_GetProperty(p_db, "id", NULL); if (s) p_struct->id=strdup(s); }

  /* member "memberFlagsMask" */
  if (p_struct->memberFlagsMask) {
    free(p_struct->memberFlagsMask);
  }
  p_struct->memberFlagsMask=NULL;
  { const char *s; s=GWEN_XMLNode_GetCharValue(p_db, "memberFlagsMask", NULL); if (s) p_struct->memberFlagsMask=strdup(s); }

  /* member "memberFlagsValue" */
  if (p_struct->memberFlagsValue) {
    free(p_struct->memberFlagsValue);
  }
  p_struct->memberFlagsValue=NULL;
  { const char *s; s=GWEN_XMLNode_GetCharValue(p_db, "memberFlagsValue", NULL); if (s) p_struct->memberFlagsValue=strdup(s); }

  /* member "code" */
  if (p_struct->code) {
    free(p_struct->code);
  }
  p_struct->code=NULL;
  { const char *s; s=GWEN_XMLNode_GetCharValue(p_db, "code", NULL); if (s) p_struct->code=strdup(s); }

  /* member "memberFlagsMaskInt" */
  p_struct->memberFlagsMaskInt=0;
  /* member "memberFlagsMaskInt" is volatile, not reading from xml */

  /* member "memberFlagsValueInt" */
  p_struct->memberFlagsValueInt=0;
  /* member "memberFlagsValueInt" is volatile, not reading from xml */

}

void Typemaker2_Code_WriteXml(const TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db) {
  assert(p_struct);
  /* member "id" */
  GWEN_XMLNode_SetProperty(p_db, "id", p_struct->id);

  /* member "memberFlagsMask" */
  GWEN_XMLNode_SetCharValue(p_db, "memberFlagsMask", p_struct->memberFlagsMask);

  /* member "memberFlagsValue" */
  GWEN_XMLNode_SetCharValue(p_db, "memberFlagsValue", p_struct->memberFlagsValue);

  /* member "code" */
  GWEN_XMLNode_SetCharValue(p_db, "code", p_struct->code);

  /* member "memberFlagsMaskInt" is volatile, not writing to xml */

  /* member "memberFlagsValueInt" is volatile, not writing to xml */

}

void Typemaker2_Code_toXml(const TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db) {
  Typemaker2_Code_WriteXml(p_struct, p_db);
}

TYPEMAKER2_CODE *Typemaker2_Code_fromXml(GWEN_XMLNODE *p_db) {
  TYPEMAKER2_CODE *p_struct;
  p_struct=Typemaker2_Code_new();
  Typemaker2_Code_ReadXml(p_struct, p_db);
  return p_struct;
}

