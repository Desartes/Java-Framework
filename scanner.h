/*******************************************************************************/
/*Projekt:Implementace interpretu imperativniho jazyka IFJ16       											           */
/*Mena riesitelov: Rastislav Pobis, Patrik Krajc , Peter Grofcik ,Filip Kolesar*/
/*Loginy riesitelov: xpobis00, xkrajc17, xgrofc00, xkoles06                    */
/*******************************************************************************/
#ifndef SCANNER_INCLUDED
#define SCANNER_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 			0
#define TRUE 			1
//Definovanie hodnôt pre scanner returnuje
#define char_LMZatvorka 12 // {
#define char_PMZatvorka 11 // }

#define char_LZatvorka  20 // (
#define char_PZatvorka  21 // )

#define char_LHZatvorka 30 // [
#define char_PHZatvorka 31 // ]

#define char_backslash  40 /* \ */ //--GOTO
#define char_uvodzovky	43 // "
#define char_dvoj_bodka	44 // :
#define char_bod_ciarka	45 // ;
#define char_ciarka 	46 // ,
#define char_apostrof	47
#define char_star		50 // *
#define char_plus		51 // +
#define char_minus		52 // -
#define char_slash      53 /* / */
#define char_rovnasa	54 // =
#define char_mensirovny 56 // <=
#define char_vacsirovny 57 // >=
#define char_nerovny 	58 // !=
#define char_rovny      59 // ==

#define char_mensi		60 // <
#define char_vacsi		61 // >
#define char_vykricnik	62 // !

#define char_bodka 		70 // .
#define char_podtr		71 // _
#define char_dolar		72 // $

#define komentar1		81 // 
#define komentar2		82 /* */
#define char_tab		83
#define char_line		84
#define print_apostrof	85
#define print_uvodzovky 86
#define char_inc 		87
#define char_dec 		88
/***************************************************
****************************************************/

#define kw_static		100

#define kw_int			101
#define kw_double		102
#define kw_string		103
#define kw_boolean		104
#define kw_void			105

#define kw_continue		110
#define kw_do 			111
#define kw_while		112
#define kw_for			113
#define kw_break		114
#define kw_run 			115
#define kw_main			116
#define kw_class		120

#define kw_else			130
#define kw_if			131

#define kw_return		140

#define kw_true			152
#define kw_false		151
#define kw_readInt		152
#define kw_readDouble	153
#define kw_readString	154	
#define kw_length		155
#define kw_print		156
#define kw_substr		157
#define kw_compare		158
#define kw_find			159
#define kw_sort			160

#define buff_size 		256

#define zaporny_exp		260
#define kladny_exp		261

#define kladny_exp_D	262
#define	zaporny_exp_D	263

#define kladny_exp_I	264
#define zaporny_exp_I	265


#define State_for_start	200
#define State_for_word	201
#define State_for_char	202
#define State_for_kw	203
#define State_for_id	204
#define State_for_digit	205

#define is_string		300
#define is_int			301
#define is_double		302
#define is_id			303
#define is_char			304

typedef struct{
	char *str;
	unsigned int length;
	unsigned int alloc;
}string;
/**
 * @brief      { init string }
 *
 * @param      s     { string }
 *
 * @return     { TRUE or ERR_INTERNAL_ERR if allocation == NULL }
 */
int init_string(string *s);
/**
 * @brief      Adds a character to string.
 *
 * @param      s     { string }
 * @param[in]  c     { char }
 *
 * @return     { TRUE or ERR_INTERNAL_ERR if allocation == NULL } 
 */
int add_char_to_String(string *s,char c);
/**
 * @brief      { deallocation  }
 *
 * @param      s     { string }
 */
void free_string(string *s);

/**
 * @brief      { Compare keywords with string }
 *
 * @param      s     { string }
 *
 * @return     { Value for a particular key word }
 */
int compare_keywords(string *s);
/**
 * @brief      Gets the token.
 *
 * @param      f     { input FILE }
 * @param      s     { string }
 *
 * @return     The token.
 */

/**
 * @brief      { function_description }
 *
 * @param      s1    The s 1
 * @param      s2    The s 2
 *
 * @return     { description_of_the_return_value }
 */
int copy_string(string *str1,string *str2);
/**
 * @brief      Gets the token.
 *
 * @param      f     { input FILE }
 * @param      s     { struct string }
 *
 * @return     The token.
 */
int get_token(FILE *f, string *s);
/**
 * @brief      { function_description }
 *
 * @param[in]  c     { parameter_description }
 *
 * @return     { 0 is specific }
 */
int isspecific(char c);
#endif