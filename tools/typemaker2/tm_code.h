/**********************************************************
 * This file has been automatically created by "typemaker2"
 * from the file "tm_code.xml".
 * Please do not edit this file, all changes will be lost.
 * Better edit the mentioned source file instead.
 **********************************************************/

#ifndef TM_CODE_H
#define TM_CODE_H


#ifdef __cplusplus
extern "C" {
#endif

/* needed system headers */
#include <gwenhywfar/types.h>
#include <gwenhywfar/list1.h>
#include <gwenhywfar/xml.h>

/* pre-headers */
#include "tm_item.h"

typedef struct TYPEMAKER2_CODE TYPEMAKER2_CODE;
GWEN_LIST_FUNCTION_DEFS(TYPEMAKER2_CODE, Typemaker2_Code)

/* post-headers */


/** Constructor. */
TYPEMAKER2_CODE *Typemaker2_Code_new();

/** Destructor. */
void Typemaker2_Code_free(TYPEMAKER2_CODE *p_struct);

TYPEMAKER2_CODE *Typemaker2_Code_dup(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "id"
*/
const char *Typemaker2_Code_GetId(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "memberFlagsMask"
*/
const char *Typemaker2_Code_GetMemberFlagsMask(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "memberFlagsValue"
*/
const char *Typemaker2_Code_GetMemberFlagsValue(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "code"
*/
const char *Typemaker2_Code_GetCode(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "memberFlagsMaskInt"
*/
uint32_t Typemaker2_Code_GetMemberFlagsMaskInt(const TYPEMAKER2_CODE *p_struct);

/** Getter.
 * Use this function to get the member "memberFlagsValueInt"
*/
uint32_t Typemaker2_Code_GetMemberFlagsValueInt(const TYPEMAKER2_CODE *p_struct);

/** Setter.
 * Use this function to set the member "id"
*/
void Typemaker2_Code_SetId(TYPEMAKER2_CODE *p_struct, const char *p_src);

/** Setter.
 * Use this function to set the member "memberFlagsMask"
*/
void Typemaker2_Code_SetMemberFlagsMask(TYPEMAKER2_CODE *p_struct, const char *p_src);

/** Setter.
 * Use this function to set the member "memberFlagsValue"
*/
void Typemaker2_Code_SetMemberFlagsValue(TYPEMAKER2_CODE *p_struct, const char *p_src);

/** Setter.
 * Use this function to set the member "code"
*/
void Typemaker2_Code_SetCode(TYPEMAKER2_CODE *p_struct, const char *p_src);

/** Setter.
 * Use this function to set the member "memberFlagsMaskInt"
*/
void Typemaker2_Code_SetMemberFlagsMaskInt(TYPEMAKER2_CODE *p_struct, uint32_t p_src);

/** Setter.
 * Use this function to set the member "memberFlagsValueInt"
*/
void Typemaker2_Code_SetMemberFlagsValueInt(TYPEMAKER2_CODE *p_struct, uint32_t p_src);

void Typemaker2_Code_ReadXml(TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db);

void Typemaker2_Code_WriteXml(const TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db);

void Typemaker2_Code_toXml(const TYPEMAKER2_CODE *p_struct, GWEN_XMLNODE *p_db);

TYPEMAKER2_CODE *Typemaker2_Code_fromXml(GWEN_XMLNODE *p_db);

#ifdef __cplusplus
}
#endif

#endif

