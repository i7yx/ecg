/* Include files */

#include "untitled_sfun.h"
#include "c3_untitled.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c3_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c3_c_emlrtMCI = { 242,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c3_d_emlrtMCI = { 245,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c3_e_emlrtMCI = { 409,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c3_f_emlrtMCI = { 420,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c3_g_emlrtMCI = { 447,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c3_h_emlrtMCI = { 398,/* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c3_i_emlrtMCI = { 419,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c3_j_emlrtMCI = { 62,/* lineNo */
  39,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c3_k_emlrtMCI = { 82,/* lineNo */
  13,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c3_l_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 13, /* lineNo */
  "MATLAB Function2",                  /* fcnName */
  "#untitled:46"                       /* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 17,/* lineNo */
  "MATLAB Function2",                  /* fcnName */
  "#untitled:46"                       /* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 16,/* lineNo */
  "MATLAB Function2",                  /* fcnName */
  "#untitled:46"                       /* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 123,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 150,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_f_emlrtRSI = { 505,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_g_emlrtRSI = { 579,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_h_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c3_i_emlrtRSI = { 174,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_j_emlrtRSI = { 261,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c3_k_emlrtRSI = { 13,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo c3_l_emlrtRSI = { 1450,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo c3_m_emlrtRSI = { 160,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_n_emlrtRSI = { 316,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_o_emlrtRSI = { 312,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_p_emlrtRSI = { 291,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_q_emlrtRSI = { 459,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_r_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c3_s_emlrtRSI = { 357,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c3_t_emlrtRSI = { 139,/* lineNo */
  "median",                            /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\median.m"/* pathName */
};

static emlrtRSInfo c3_u_emlrtRSI = { 108,/* lineNo */
  "vmedian",                           /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vmedian.m"/* pathName */
};

static emlrtRSInfo c3_v_emlrtRSI = { 113,/* lineNo */
  "vmedian",                           /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vmedian.m"/* pathName */
};

static emlrtRSInfo c3_w_emlrtRSI = { 94,/* lineNo */
  "quickselect",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\quickselect.m"/* pathName */
};

static emlrtRSInfo c3_x_emlrtRSI = { 177,/* lineNo */
  "quickselect",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\quickselect.m"/* pathName */
};

static emlrtRSInfo c3_y_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c3_ab_emlrtRSI = { 134,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_bb_emlrtRSI = { 166,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_cb_emlrtRSI = { 167,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_db_emlrtRSI = { 178,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_eb_emlrtRSI = { 182,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_fb_emlrtRSI = { 189,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_gb_emlrtRSI = { 195,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_hb_emlrtRSI = { 566,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_ib_emlrtRSI = { 23,/* lineNo */
  "union",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\union.m"/* pathName */
};

static emlrtRSInfo c3_jb_emlrtRSI = { 97,/* lineNo */
  "eml_setop",                         /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo c3_kb_emlrtRSI = { 579,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_lb_emlrtRSI = { 641,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c3_mb_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c3_nb_emlrtRSI = { 82,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c3_ob_emlrtRSI = { 140,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c3_pb_emlrtRSI = { 42,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_qb_emlrtRSI = { 44,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_rb_emlrtRSI = { 47,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_sb_emlrtRSI = { 55,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_tb_emlrtRSI = { 58,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_ub_emlrtRSI = { 41,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c3_vb_emlrtRSI = { 18,/* lineNo */
  "insertionsort",                     /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pathName */
};

static emlrtRSInfo c3_wb_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sparse",                            /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 439,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_c_emlrtRTEI = { 440,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 441,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 526,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 527,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_g_emlrtRTEI = { 548,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_h_emlrtRTEI = { 562,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_i_emlrtRTEI = { 167,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_j_emlrtRTEI = { 178,/* lineNo */
  47,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_k_emlrtRTEI = { 584,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_l_emlrtRTEI = { 585,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_m_emlrtRTEI = { 593,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_n_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c3_o_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c3_p_emlrtRTEI = { 598,/* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_q_emlrtRTEI = { 598,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_r_emlrtRTEI = { 600,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_s_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_t_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c3_u_emlrtRTEI = { 579,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_v_emlrtRTEI = { 182,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_w_emlrtRTEI = { 191,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_x_emlrtRTEI = { 187,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_y_emlrtRTEI = { 189,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_ab_emlrtRTEI = { 195,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_bb_emlrtRTEI = { 679,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_cb_emlrtRTEI = { 680,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c3_db_emlrtRTEI = { 223,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_eb_emlrtRTEI = { 224,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_fb_emlrtRTEI = { 225,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_gb_emlrtRTEI = { 415,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_hb_emlrtRTEI = { 426,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_ib_emlrtRTEI = { 451,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c3_jb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "introsort",                         /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pName */
};

static emlrtRTEInfo c3_kb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "insertionsort",                     /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pName */
};

static emlrtRTEInfo c3_lb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c3_mb_emlrtRTEI = { 40,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c3_nb_emlrtRTEI = { 48,/* lineNo */
  45,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtRTEInfo c3_ob_emlrtRTEI = { 261,/* lineNo */
  19,                                  /* colNo */
  "filtfilt",                          /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pName */
};

static emlrtBCInfo c3_emlrtBCI = { 1,  /* iFirst */
  128,                                 /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 52, /* lineNo */
  27,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  41,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_b_emlrtDCI = { 41,/* lineNo */
  27,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c3_pb_emlrtRTEI = { 34,/* lineNo */
  19,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46"                       /* pName */
};

static emlrtRTEInfo c3_qb_emlrtRTEI = { 29,/* lineNo */
  13,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46"                       /* pName */
};

static emlrtBCInfo c3_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  23,                                  /* colNo */
  "peak_locs",                         /* aName */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_c_emlrtDCI = { 30,/* lineNo */
  23,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_d_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  52,                                  /* lineNo */
  44,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_d_emlrtDCI = { 52,/* lineNo */
  44,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_e_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  52,                                  /* lineNo */
  64,                                  /* colNo */
  "sigmoid_trans",                     /* aName */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_e_emlrtDCI = { 52,/* lineNo */
  64,                                  /* colNo */
  "MATLAB Function2",                  /* fName */
  "#untitled:46",                      /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c3_rb_emlrtRTEI = { 618,/* lineNo */
  18,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtBCInfo c3_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  528,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  527,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  475,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  526,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  502,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  523,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  511,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  497,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  489,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_t_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  553,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_u_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  555,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_v_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  555,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  558,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  598,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  603,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  628,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  623,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  85,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_f_emlrtDCI = { 48,/* lineNo */
  63,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m",/* pName */
  4                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void initialize_params_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static void mdl_start_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void mdl_terminate_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c3_untitled(SFc3_untitledInstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c3_untitled
  (SFc3_untitledInstanceStruct *chartInstance);
static void enable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void disable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void sf_gateway_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void ext_mode_exec_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void c3_update_jit_animation_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static void c3_do_animation_call_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c3_untitled(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_filtfilt(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_varargin_2[128], real_T c3_y[128]);
static void c3_introsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp, int32_T c3_b_x[4]);
static void c3_insertionsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp, int32_T c3_b_x[4]);
static void c3_check_forloop_overflow_error(SFc3_untitledInstanceStruct
  *chartInstance, const emlrtStack *c3_sp);
static void c3_warning(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp);
static void c3_filter(SFc3_untitledInstanceStruct *chartInstance, real_T c3_b[3],
                      real_T c3_x[140], real_T c3_zi[2], real_T c3_y[140]);
static void c3_pivot(SFc3_untitledInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_v[128], int32_T c3_ip, int32_T
                     c3_ia, int32_T c3_ib, real_T c3_b_v[128], int32_T *c3_b_ip,
                     int32_T *c3_reps);
static void c3_medmed(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
                      [128], int32_T c3_nv, int32_T c3_ia, real_T c3_b_v[128]);
static int32_T c3_thirdOfFive(SFc3_untitledInstanceStruct *chartInstance, real_T
  c3_v[128], int32_T c3_ia, int32_T c3_ib);
static void c3_med3(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v[128],
                    int32_T c3_nv, int32_T c3_ia, int32_T c3_ib, real_T c3_b_v
                    [128]);
static void c3_findpeaks(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_Yin[128], real_T c3_varargin_2, real_T
  c3_Ypk_data[], int32_T c3_Ypk_size[1], real_T c3_Xpk_data[], int32_T
  c3_Xpk_size[1]);
static void c3_do_vectors(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_a_data[], int32_T c3_a_size[1], int32_T
  c3_b_data[], int32_T c3_b_size[1], int32_T c3_c_data[], int32_T c3_c_size[1],
  int32_T c3_ia_data[], int32_T c3_ia_size[1], int32_T c3_ib_data[], int32_T
  c3_ib_size[1]);
static boolean_T c3_issorted(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1]);
static void c3_b_introsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_x_size[1], int32_T c3_xend,
  int32_T c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_b_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x_data[], int32_T c3_x_size[1], int32_T c3_xend, int32_T
  c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_c_insertionsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_x_size[1], int32_T
  c3_xstart, int32_T c3_xend, int32_T c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_heapsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1], int32_T c3_xstart, int32_T c3_xend, int32_T
  c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_heapify(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1], int32_T c3_idx, int32_T c3_xstart, int32_T
  c3_xend, int32_T c3_b_x_data[], int32_T c3_b_x_size[1]);
static void c3_indexShapeCheck(SFc3_untitledInstanceStruct *chartInstance);
static void c3_b_indexShapeCheck(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_matrixSize, int32_T c3_indexSize[2]);
static void c3_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier, real_T c3_y[128]);
static void c3_b_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[128]);
static void c3_slStringInitializeDynamicBuffers(SFc3_untitledInstanceStruct
  *chartInstance);
static const mxArray *c3_feval(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1);
static void c3_b_feval(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1);
static void c3_c_introsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp);
static void c3_d_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x[4], c3_anonymous_function c3_cmp);
static int32_T c3_b_pivot(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_v[128], int32_T *c3_ip, int32_T c3_ia, int32_T
  c3_ib);
static void c3_b_medmed(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
  [128], int32_T c3_nv, int32_T c3_ia);
static void c3_b_med3(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
                      [128], int32_T c3_nv, int32_T c3_ia, int32_T c3_ib);
static void c3_d_introsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_xend);
static void c3_e_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x_data[], int32_T c3_xend);
static void c3_f_insertionsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_xstart, int32_T c3_xend);
static void c3_b_heapsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_xstart, int32_T c3_xend);
static void c3_b_heapify(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_idx, int32_T c3_xstart, int32_T c3_xend);
static void c3_array_real_T_SetSize(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, c3_coder_array_real_T *c3_coderArray, const
  emlrtRTEInfo *c3_srcLocation, int32_T c3_size0);
static void c3_array_int32_T_SetSize(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, c3_coder_array_int32_T *c3_coderArray, const
  emlrtRTEInfo *c3_srcLocation, int32_T c3_size0);
static void c3_array_sparse_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_sparse *c3_pStruct);
static void c3_array_real_T_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_real_T *c3_coderArray);
static void c3_array_int32_T_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_int32_T *c3_coderArray);
static void c3_array_real_T_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_real_T *c3_coderArray);
static void c3_array_sparse_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_sparse *c3_pStruct);
static void c3_array_int32_T_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_int32_T *c3_coderArray);
static int32_T c3_div_nzp_s32(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_numerator, int32_T c3_denominator, int32_T c3_EMLOvCount_src_loc,
  uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc);
static void init_dsm_address_info(SFc3_untitledInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c3_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "signal_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_doneDoubleBufferReInit = false;
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c3_untitled(SFc3_untitledInstanceStruct *
  chartInstance)
{
  static const int32_T c3_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_condTxtEndIdx[2] = { 1142, 1156 };

  static const int32_T c3_condTxtStartIdx[2] = { 1134, 1146 };

  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c3_JITStateAnimation[0],
                        &chartInstance->c3_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    10U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 5U, 0U,
                  0U, 0U, 2U, 0U, 2U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, "c3_untitled",
                     0, -1, 2012);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 260, 287, -1,
                    323, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1131, 1156, -1,
                    1915, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1289, 1316,
                    1402, 1880, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 1402, 1447, -1,
                    1880, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 1561, 1572,
                    1668, 1771, false);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 887, 914, 1935);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1047, 1118,
                     1927);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 1134, 1156,
                      2U, 0U, &c3_condTxtStartIdx[0], &c3_condTxtEndIdx[0], 3U,
                      &c3_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 263,
    287, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 1134,
    1142, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1146,
    1156, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 1292,
    1316, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 1409,
    1447, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 1564,
    1572, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c3_untitled
  (SFc3_untitledInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  static real_T c3_dv[5] = { 4.5397868702434395E-5, 0.0066928509242848554, 0.5,
    0.99330714907571527, 0.99995460213129761 };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_a3_smoothed_full[128];
  real_T c3_a__1_data[128];
  real_T c3_alpha[128];
  real_T c3_b_a3_in[128];
  real_T c3_c_y[128];
  real_T c3_peak_locs_data[128];
  real_T c3_b_b;
  real_T c3_b_idx;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_i;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_c;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_dist;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_i_x;
  real_T c3_i_y;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_l_x;
  real_T c3_l_y;
  real_T c3_m;
  real_T c3_m1;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_minval;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_rel_idx;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_x;
  real_T c3_y;
  int32_T c3_a__1_size[1];
  int32_T c3_peak_locs_size[1];
  int32_T c3_a;
  int32_T c3_b_a;
  int32_T c3_b_c;
  int32_T c3_b_i;
  int32_T c3_b_ia;
  int32_T c3_b_ib;
  int32_T c3_b_ifirst;
  int32_T c3_b_ilast;
  int32_T c3_b_ipiv;
  int32_T c3_b_k;
  int32_T c3_b_nv;
  int32_T c3_b_oldnv;
  int32_T c3_b_reps;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_c;
  int32_T c3_c_ifirst;
  int32_T c3_c_ilast;
  int32_T c3_c_k;
  int32_T c3_d_ilast;
  int32_T c3_d_k;
  int32_T c3_e_a;
  int32_T c3_e_c;
  int32_T c3_e_ilast;
  int32_T c3_e_k;
  int32_T c3_exitg1;
  int32_T c3_f_a;
  int32_T c3_f_c;
  int32_T c3_f_k;
  int32_T c3_g_a;
  int32_T c3_g_c;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_ia;
  int32_T c3_ib;
  int32_T c3_idx;
  int32_T c3_ifirst;
  int32_T c3_ilast;
  int32_T c3_ipiv;
  int32_T c3_k;
  int32_T c3_nv;
  int32_T c3_oldnv;
  int32_T c3_reps;
  int32_T c3_vlen;
  boolean_T c3_b;
  boolean_T c3_b_checkspeed;
  boolean_T c3_b_isslow;
  boolean_T c3_c_b;
  boolean_T c3_checkspeed;
  boolean_T c3_exitg2;
  boolean_T c3_guard1;
  boolean_T c3_isslow;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  for (c3_i = 0; c3_i < 128; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U,
                      (*chartInstance->c3_a3_in)[c3_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  chartInstance->c3_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  for (c3_i1 = 0; c3_i1 < 128; c3_i1++) {
    c3_b_a3_in[c3_i1] = (*chartInstance->c3_a3_in)[c3_i1];
  }

  covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                 covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U,
    0U, 0U, 1.0, 0.0, -1, 0U, 0));
  c3_b_st.site = &c3_emlrtRSI;
  c3_filtfilt(chartInstance, &c3_b_st, c3_b_a3_in, c3_a3_smoothed_full);
  for (c3_k = 0; c3_k < 128; c3_k++) {
    c3_c_k = c3_k;
    c3_x = c3_b_a3_in[c3_c_k];
    c3_y = muDoubleScalarAbs(c3_x);
    c3_alpha[c3_c_k] = c3_y;
  }

  for (c3_b_k = 0; c3_b_k < 128; c3_b_k++) {
    c3_d_k = c3_b_k;
    c3_b_x = c3_b_a3_in[c3_d_k];
    c3_b_y = muDoubleScalarAbs(c3_b_x);
    c3_c_y[c3_d_k] = c3_b_y;
  }

  c3_b_st.site = &c3_b_emlrtRSI;
  c3_c_st.site = &c3_t_emlrtRSI;
  c3_e_k = 1;
  do {
    c3_exitg1 = 0;
    if (c3_e_k - 1 < 128) {
      c3_f_k = c3_e_k - 1;
      c3_c_x = c3_c_y[c3_f_k];
      c3_b = muDoubleScalarIsNaN(c3_c_x);
      if (c3_b) {
        c3_d = rtNaN;
        c3_exitg1 = 1;
      } else {
        c3_e_k++;
      }
    } else {
      c3_d_st.site = &c3_u_emlrtRSI;
      c3_ipiv = 65;
      c3_ia = 1;
      c3_ib = 128;
      c3_ifirst = 1;
      c3_ilast = 127;
      c3_oldnv = 128;
      c3_checkspeed = false;
      c3_isslow = false;
      c3_exitg2 = false;
      while ((!c3_exitg2) && (c3_ia < c3_ib)) {
        c3_b_ilast = c3_ipiv;
        c3_e_st.site = &c3_w_emlrtRSI;
        c3_reps = c3_b_pivot(chartInstance, &c3_e_st, c3_c_y, &c3_b_ilast, c3_ia,
                             c3_ib);
        c3_ilast = c3_b_ilast - 1;
        c3_guard1 = false;
        if (c3_b_ilast >= 65) {
          c3_ifirst = c3_b_ilast - c3_reps;
          if (c3_ifirst <= 65) {
            c3_exitg2 = true;
          } else {
            c3_ib = c3_b_ilast - 1;
            c3_guard1 = true;
          }
        } else {
          c3_ia = c3_b_ilast + 1;
          c3_guard1 = true;
        }

        if (c3_guard1) {
          c3_c_a = c3_ib - c3_ia;
          c3_c_c = c3_c_a + 1;
          c3_nv = c3_c_c;
          if (c3_checkspeed) {
            c3_e_a = c3_oldnv;
            c3_e_c = c3_div_nzp_s32(chartInstance, c3_e_a, 2, 0, 1U, 545, 18);
            c3_isslow = (c3_nv > c3_e_c);
            c3_oldnv = c3_nv;
          }

          c3_checkspeed = !c3_checkspeed;
          if (c3_isslow) {
            c3_b_medmed(chartInstance, c3_c_y, c3_nv, c3_ia);
          } else {
            c3_b_med3(chartInstance, c3_c_y, c3_nv, c3_ia, c3_ib);
          }

          c3_ipiv = c3_ia;
          c3_ifirst = c3_ia;
          c3_ilast = c3_ib - 1;
        }
      }

      c3_m = c3_c_y[c3_ilast];
      c3_a = c3_ifirst;
      c3_c = c3_a;
      c3_b_ifirst = c3_c;
      c3_b_a = c3_ilast;
      c3_b_c = c3_b_a + 1;
      c3_c_ilast = c3_b_c - 1;
      c3_d = c3_m;
      if (c3_b_ifirst > 64) {
        c3_d_st.site = &c3_v_emlrtRSI;
        c3_vlen = c3_c_ilast;
        if (c3_vlen < 64) {
          c3_m1 = rtNaN;
        } else {
          c3_b_ipiv = 64;
          c3_b_ia = 1;
          c3_b_ib = c3_vlen;
          c3_d_ilast = c3_vlen;
          c3_b_oldnv = c3_vlen;
          c3_b_checkspeed = false;
          c3_b_isslow = false;
          c3_exitg2 = false;
          while ((!c3_exitg2) && (c3_b_ia < c3_b_ib)) {
            c3_e_ilast = c3_b_ipiv;
            c3_e_st.site = &c3_w_emlrtRSI;
            c3_b_reps = c3_b_pivot(chartInstance, &c3_e_st, c3_c_y, &c3_e_ilast,
              c3_b_ia, c3_b_ib);
            c3_d_ilast = c3_e_ilast;
            c3_guard1 = false;
            if (c3_e_ilast >= 64) {
              c3_c_ifirst = c3_e_ilast - c3_b_reps;
              if (c3_c_ifirst <= 64) {
                c3_exitg2 = true;
              } else {
                c3_b_ib = c3_e_ilast - 1;
                c3_guard1 = true;
              }
            } else {
              c3_b_ia = c3_e_ilast + 1;
              c3_guard1 = true;
            }

            if (c3_guard1) {
              c3_f_a = c3_b_ib - c3_b_ia;
              c3_f_c = c3_f_a + 1;
              c3_b_nv = c3_f_c;
              if (c3_b_checkspeed) {
                c3_g_a = c3_b_oldnv;
                c3_g_c = c3_div_nzp_s32(chartInstance, c3_g_a, 2, 0, 1U, 545, 18);
                c3_b_isslow = (c3_b_nv > c3_g_c);
                c3_b_oldnv = c3_b_nv;
              }

              c3_b_checkspeed = !c3_b_checkspeed;
              if (c3_b_isslow) {
                c3_b_medmed(chartInstance, c3_c_y, c3_b_nv, c3_b_ia);
              } else {
                c3_b_med3(chartInstance, c3_c_y, c3_b_nv, c3_b_ia, c3_b_ib);
              }

              c3_b_ipiv = c3_b_ia;
              c3_d_ilast = c3_b_ib;
            }
          }

          c3_m1 = c3_c_y[c3_d_ilast - 1];
        }

        c3_d_a = c3_m;
        c3_b_b = c3_m1;
        c3_d_x = c3_d_a;
        c3_c_b = muDoubleScalarIsInf(c3_d_x);
        if (c3_c_b) {
          c3_d4 = (c3_d_a + c3_b_b) / 2.0;
        } else {
          c3_d4 = c3_d_a + (c3_b_b - c3_d_a) / 2.0;
        }

        c3_d = c3_d4;
      }

      c3_exitg1 = 1;
    }
  } while (c3_exitg1 == 0);

  c3_d_y = c3_d;
  c3_b_st.site = &c3_c_emlrtRSI;
  c3_findpeaks(chartInstance, &c3_b_st, c3_alpha, 0.6 * c3_d_y, c3_a__1_data,
               c3_a__1_size, c3_peak_locs_data, c3_peak_locs_size);
  for (c3_i2 = 0; c3_i2 < 128; c3_i2++) {
    c3_alpha[c3_i2] = 1.0;
  }

  c3_d1 = (real_T)c3_peak_locs_size[0];
  c3_i3 = (int32_T)c3_d1;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d1, mxDOUBLE_CLASS, c3_i3,
    &c3_qb_emlrtRTEI, &c3_st);
  for (c3_b_i = 0; c3_b_i < c3_i3; c3_b_i++) {
    c3_c_i = 1.0 + (real_T)c3_b_i;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 1);
    if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
      emlrtIntegerCheckR2012b(c3_c_i, &c3_c_emlrtDCI, &c3_st);
    }

    c3_i6 = (int32_T)c3_c_i;
    if ((c3_i6 < 1) || (c3_i6 > c3_peak_locs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i6, 1, c3_peak_locs_size[0],
        &c3_c_emlrtBCI, &c3_st);
    }

    c3_d_c = c3_peak_locs_data[c3_i6 - 1];
    c3_d2 = (c3_d_c - 3.0) - 2.0;
    c3_d3 = (c3_d_c + 3.0) + 2.0;
    c3_i7 = (int32_T)(c3_d3 + (1.0 - c3_d2));
    emlrtForLoopVectorCheckR2021a(c3_d2, 1.0, c3_d3, mxDOUBLE_CLASS, c3_i7,
      &c3_pb_emlrtRTEI, &c3_st);
    for (c3_idx = 0; c3_idx < c3_i7; c3_idx++) {
      c3_b_idx = c3_d2 + (real_T)c3_idx;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 1);
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 1U,
                            c3_b_idx, 1.0, -1, 5U, c3_b_idx >= 1.0)) &&
          covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 1,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 2U,
                            c3_b_idx, 128.0, -1, 3U, c3_b_idx <= 128.0))) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1, true);
        c3_dist = c3_b_idx - c3_d_c;
        c3_e_x = c3_dist;
        c3_f_x = c3_e_x;
        c3_g_x = c3_f_x;
        c3_e_y = muDoubleScalarAbs(c3_g_x);
        c3_h_x = c3_dist;
        c3_i_x = c3_h_x;
        c3_j_x = c3_i_x;
        c3_f_y = muDoubleScalarAbs(c3_j_x);
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 2,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 3U, c3_e_y,
                            3.0, -1, 3U, c3_f_y <= 3.0))) {
          if (c3_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c3_b_idx)) {
            emlrtIntegerCheckR2012b(c3_b_idx, &c3_b_emlrtDCI, &c3_st);
          }

          c3_i8 = (int32_T)c3_b_idx;
          if ((c3_i8 < 1) || (c3_i8 > 128)) {
            emlrtDynamicBoundsCheckR2012b(c3_i8, 1, 128, &c3_b_emlrtBCI, &c3_st);
          }

          c3_alpha[c3_i8 - 1] = 0.0;
        } else {
          c3_k_x = c3_dist;
          c3_l_x = c3_k_x;
          c3_m_x = c3_l_x;
          c3_g_y = muDoubleScalarAbs(c3_m_x);
          c3_n_x = c3_dist;
          c3_o_x = c3_n_x;
          c3_p_x = c3_o_x;
          c3_h_y = muDoubleScalarAbs(c3_p_x);
          if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c3_covrtInstance, 4U, 0U, 4U,
                              c3_g_y, 5.0, -1, 3U, c3_h_y <= 5.0))) {
            if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 5U,
                                c3_dist, 0.0, -1, 2U, c3_dist < 0.0))) {
              c3_rel_idx = ((c3_dist + 3.0) + 2.0) + 1.0;
            } else {
              c3_rel_idx = ((c3_dist - 3.0) + 2.0) + 1.0;
            }

            if (c3_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c3_b_idx)) {
              emlrtIntegerCheckR2012b(c3_b_idx, &c3_d_emlrtDCI, &c3_st);
            }

            c3_i9 = (int32_T)c3_b_idx;
            if ((c3_i9 < 1) || (c3_i9 > 128)) {
              emlrtDynamicBoundsCheckR2012b(c3_i9, 1, 128, &c3_d_emlrtBCI,
                &c3_st);
            }

            c3_varargin_1 = c3_alpha[c3_i9 - 1];
            if (c3_rel_idx != (real_T)(int32_T)muDoubleScalarFloor(c3_rel_idx))
            {
              emlrtIntegerCheckR2012b(c3_rel_idx, &c3_e_emlrtDCI, &c3_st);
            }

            c3_i10 = (int32_T)c3_rel_idx;
            if ((c3_i10 < 1) || (c3_i10 > 5)) {
              emlrtDynamicBoundsCheckR2012b(c3_i10, 1, 5, &c3_e_emlrtBCI, &c3_st);
            }

            c3_varargin_2 = c3_dv[c3_i10 - 1];
            c3_q_x = c3_varargin_1;
            c3_i_y = c3_varargin_2;
            c3_r_x = c3_q_x;
            c3_j_y = c3_i_y;
            c3_s_x = c3_r_x;
            c3_k_y = c3_j_y;
            c3_h_a = c3_s_x;
            c3_d_b = c3_k_y;
            c3_t_x = c3_h_a;
            c3_l_y = c3_d_b;
            c3_u_x = c3_t_x;
            c3_m_y = c3_l_y;
            c3_minval = muDoubleScalarMin(c3_u_x, c3_m_y);
            if (c3_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c3_b_idx)) {
              emlrtIntegerCheckR2012b(c3_b_idx, &c3_emlrtDCI, &c3_st);
            }

            c3_i11 = (int32_T)c3_b_idx;
            if ((c3_i11 < 1) || (c3_i11 > 128)) {
              emlrtDynamicBoundsCheckR2012b(c3_i11, 1, 128, &c3_emlrtBCI, &c3_st);
            }

            c3_alpha[c3_i11 - 1] = c3_minval;
          }
        }
      } else {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, false);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1, false);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 0);
  for (c3_i4 = 0; c3_i4 < 128; c3_i4++) {
    (*chartInstance->c3_a3_smoothed)[c3_i4] = c3_a3_smoothed_full[c3_i4] *
      c3_alpha[c3_i4] + c3_b_a3_in[c3_i4] * (1.0 - c3_alpha[c3_i4]);
  }

  for (c3_i5 = 0; c3_i5 < 128; c3_i5++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U,
                      (*chartInstance->c3_a3_smoothed)[c3_i5]);
  }
}

static void ext_mode_exec_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_update_jit_animation_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(1, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_a3_smoothed, 0,
    0U, 1, 0U, 2, 128, 1), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_untitled(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv[128];
  int32_T c3_i;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "a3_smoothed", c3_dv);
  for (c3_i = 0; c3_i < 128; c3_i++) {
    (*chartInstance->c3_a3_smoothed)[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void c3_filtfilt(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_varargin_2[128], real_T c3_y[128])
{
  static real_T c3_dv[4] = { 1.0, 0.0, 1.0, -1.0 };

  static real_T c3_B[3] = { 0.068965517241379309, 0.86206896551724133,
    0.068965517241379309 };

  static real_T c3_dv1[2] = { 0.86206896551724133, 0.068965517241379309 };

  static real_T c3_rhs[2] = { 0.86206896551724133, 0.068965517241379309 };

  static int32_T c3_a[4] = { 1, 1, 2, 2 };

  static int32_T c3_e_b[4] = { 1, 2, 2, 1 };

  static char_T c3_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c3_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'f', 'i', 'l',
    't', 'f', 'i', 'l', 't', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
    'i', 'n', 'i', 't', 'e' };

  static char_T c3_cv2[12] = { 'i', 'n', 'p', 'u', 't', ' ', 's', 'i', 'g', 'n',
    'a', 'l' };

  cs_di *c3_b_cxA;
  cs_di *c3_cxA;
  cs_din *c3_N;
  cs_din *c3_b_N;
  cs_dis *c3_S;
  cs_dis *c3_b_S;
  c3_anonymous_function c3_this;
  c3_sFhFjA9rDll2zuJpMfejXjH c3_workspace;
  c3_sparse c3_e_y;
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_f_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_ytemp[140];
  real_T c3_c_ytemp[140];
  real_T c3_d_ytemp[140];
  real_T c3_ytemp[140];
  real_T c3_f_y[2];
  real_T c3_outBuff[2];
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_f_b;
  real_T c3_g_b;
  real_T c3_tol;
  real_T c3_val;
  real_T c3_x;
  int32_T c3_cidxInt[4];
  int32_T c3_ridxInt[4];
  int32_T c3_sortedIndices[4];
  int32_T c3_b_c;
  int32_T c3_b_n;
  int32_T c3_c;
  int32_T c3_c_c;
  int32_T c3_c_k;
  int32_T c3_cptr;
  int32_T c3_currRowIdx;
  int32_T c3_d_c;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_g_k;
  int32_T c3_h_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i_k;
  int32_T c3_idx;
  int32_T c3_k;
  int32_T c3_n;
  int32_T c3_ridx;
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b2;
  boolean_T c3_b_b;
  boolean_T c3_c_b;
  boolean_T c3_d_b;
  boolean_T c3_exitg1;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_f_st.prev = &c3_e_st;
  c3_f_st.tls = c3_e_st.tls;
  c3_st.site = &c3_d_emlrtRSI;
  c3_b_st.site = &c3_f_emlrtRSI;
  c3_c_st.site = &c3_g_emlrtRSI;
  c3_d_st.site = &c3_h_emlrtRSI;
  c3_p = true;
  c3_k = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_k < 128)) {
    c3_b_k = (real_T)c3_k + 1.0;
    c3_x = c3_varargin_2[(int32_T)c3_b_k - 1];
    c3_b_x = c3_x;
    c3_b_b = muDoubleScalarIsInf(c3_b_x);
    c3_b1 = !c3_b_b;
    c3_c_x = c3_x;
    c3_c_b = muDoubleScalarIsNaN(c3_c_x);
    c3_b2 = !c3_c_b;
    c3_d_b = (c3_b1 && c3_b2);
    if (c3_d_b) {
      c3_k++;
    } else {
      c3_p = false;
      c3_exitg1 = true;
    }
  }

  if (c3_p) {
    c3_b = true;
  } else {
    c3_b = false;
  }

  if (!c3_b) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    sf_mex_call(&c3_d_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_d_st, NULL, "message", 1U, 2U, 14, c3_c_y, 14, c3_d_y)));
  }

  c3_st.site = &c3_e_emlrtRSI;
  c3_b_st.site = &c3_i_emlrtRSI;
  c3_c_st.site = &c3_j_emlrtRSI;
  c3_d_st.site = &c3_k_emlrtRSI;
  c3_array_sparse_Constructor(chartInstance, &c3_e_y);
  for (c3_c_k = 0; c3_c_k < 4; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_sortedIndices[c3_d_k] = c3_d_k + 1;
  }

  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_workspace.a[c3_i] = c3_a[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_workspace.b[c3_i1] = c3_e_b[c3_i1];
  }

  c3_this.workspace = c3_workspace;
  c3_c_introsort(chartInstance, c3_sortedIndices, c3_this);
  for (c3_e_k = 0; c3_e_k < 4; c3_e_k++) {
    c3_g_k = c3_e_k;
    c3_cidxInt[c3_g_k] = c3_a[c3_sortedIndices[c3_g_k] - 1];
  }

  for (c3_f_k = 0; c3_f_k < 4; c3_f_k++) {
    c3_h_k = c3_f_k;
    c3_ridxInt[c3_h_k] = c3_e_b[c3_sortedIndices[c3_h_k] - 1];
  }

  c3_array_real_T_SetSize(chartInstance, &c3_d_st, &c3_e_y.d, &c3_emlrtRTEI, 4);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_e_y.d.vector.data[c3_i2] = 0.0;
  }

  c3_array_int32_T_SetSize(chartInstance, &c3_d_st, &c3_e_y.colidx,
    &c3_emlrtRTEI, 3);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_e_y.colidx.vector.data[c3_i3] = 0;
  }

  c3_e_y.colidx.vector.data[0] = 1;
  c3_array_int32_T_SetSize(chartInstance, &c3_d_st, &c3_e_y.rowidx,
    &c3_emlrtRTEI, 4);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_e_y.rowidx.vector.data[c3_i4] = 0;
  }

  c3_cptr = 0;
  for (c3_c = 0; c3_c < 2; c3_c++) {
    c3_b_c = c3_c + 1;
    while ((c3_cptr + 1 <= 4) && (c3_cidxInt[c3_cptr] == c3_b_c)) {
      c3_e_y.rowidx.vector.data[c3_cptr] = c3_ridxInt[c3_cptr];
      c3_cptr++;
    }

    c3_e_y.colidx.vector.data[c3_b_c] = c3_cptr + 1;
  }

  for (c3_i_k = 0; c3_i_k < 4; c3_i_k++) {
    c3_d_k = c3_i_k;
    c3_e_y.d.vector.data[c3_d_k] = c3_dv[c3_sortedIndices[c3_d_k] - 1];
  }

  c3_idx = 0;
  c3_i5 = c3_e_y.colidx.size[0] - 2;
  for (c3_c_c = 0; c3_c_c <= c3_i5; c3_c_c++) {
    c3_d_c = c3_c_c;
    c3_ridx = c3_e_y.colidx.vector.data[c3_d_c] - 1;
    c3_e_y.colidx.vector.data[c3_d_c] = c3_idx + 1;
    while (c3_ridx + 1 < c3_e_y.colidx.vector.data[c3_d_c + 1]) {
      c3_val = 0.0;
      c3_currRowIdx = c3_e_y.rowidx.vector.data[c3_ridx];
      while ((c3_ridx + 1 < c3_e_y.colidx.vector.data[c3_d_c + 1]) &&
             (c3_e_y.rowidx.vector.data[c3_ridx] == c3_currRowIdx)) {
        c3_val += c3_e_y.d.vector.data[c3_ridx];
        c3_ridx++;
      }

      if (c3_val != 0.0) {
        c3_e_y.d.vector.data[c3_idx] = c3_val;
        c3_e_y.rowidx.vector.data[c3_idx] = c3_currRowIdx;
        c3_idx++;
      }
    }
  }

  c3_e_y.colidx.vector.data[c3_e_y.colidx.size[0] - 1] = c3_idx + 1;
  c3_c_st.site = &c3_j_emlrtRSI;
  c3_d_st.site = &c3_l_emlrtRSI;
  c3_e_st.site = &c3_m_emlrtRSI;
  c3_f_st.site = &c3_p_emlrtRSI;
  c3_n = c3_e_y.colidx.vector.data[c3_e_y.colidx.size[0] - 1];
  c3_cxA = makeCXSparseMatrix(c3_n - 1, 2, 2, &c3_e_y.colidx.vector.data[0],
    &c3_e_y.rowidx.vector.data[0], &c3_e_y.d.vector.data[0]);
  c3_S = cs_di_sqr(2, c3_cxA, 0);
  c3_N = cs_di_lu(c3_cxA, c3_S, 1);
  cs_di_spfree(c3_cxA);
  if (c3_N == NULL) {
    c3_f_st.site = &c3_o_emlrtRSI;
    c3_warning(chartInstance, &c3_f_st);
    cs_di_sfree(c3_S);
    cs_di_nfree(c3_N);
    c3_b_n = c3_e_y.colidx.vector.data[c3_e_y.colidx.size[0] - 1];
    c3_b_cxA = makeCXSparseMatrix(c3_b_n - 1, 2, 2, &c3_e_y.colidx.vector.data[0],
      &c3_e_y.rowidx.vector.data[0], &c3_e_y.d.vector.data[0]);
    c3_b_S = cs_di_sqr(2, c3_b_cxA, 1);
    c3_b_N = cs_di_qr(c3_b_cxA, c3_b_S);
    cs_di_spfree(c3_b_cxA);
    qr_rank_di(c3_b_N, &c3_tol);
    for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
      c3_outBuff[c3_i8] = c3_dv1[c3_i8];
    }

    solve_from_qr_di(c3_b_N, c3_b_S, (double *)&c3_outBuff[0], 2, 2);
    cs_di_sfree(c3_b_S);
    cs_di_nfree(c3_b_N);
  } else {
    for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
      c3_outBuff[c3_i6] = c3_rhs[c3_i6];
    }

    solve_from_lu_di(c3_N, c3_S, (double *)&c3_outBuff[0], 2);
    cs_di_sfree(c3_S);
    cs_di_nfree(c3_N);
  }

  c3_array_sparse_Destructor(chartInstance, &c3_e_y);
  c3_d = 2.0 * c3_varargin_2[0];
  c3_d1 = 2.0 * c3_varargin_2[127];
  for (c3_i7 = 0; c3_i7 < 6; c3_i7++) {
    c3_ytemp[c3_i7] = c3_d - c3_varargin_2[6 - c3_i7];
  }

  for (c3_i9 = 0; c3_i9 < 128; c3_i9++) {
    c3_ytemp[c3_i9 + 6] = c3_varargin_2[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
    c3_ytemp[c3_i10 + 134] = c3_d1 - c3_varargin_2[126 - c3_i10];
  }

  c3_f_b = c3_ytemp[0];
  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    c3_f_y[c3_i11] = c3_outBuff[c3_i11] * c3_f_b;
  }

  for (c3_i12 = 0; c3_i12 < 140; c3_i12++) {
    c3_b_ytemp[c3_i12] = c3_ytemp[c3_i12];
  }

  c3_filter(chartInstance, c3_B, c3_b_ytemp, c3_f_y, c3_ytemp);
  for (c3_i13 = 0; c3_i13 < 140; c3_i13++) {
    c3_c_ytemp[c3_i13] = c3_ytemp[139 - c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 140; c3_i14++) {
    c3_ytemp[c3_i14] = c3_c_ytemp[c3_i14];
  }

  c3_g_b = c3_ytemp[0];
  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_outBuff[c3_i15] *= c3_g_b;
  }

  for (c3_i16 = 0; c3_i16 < 140; c3_i16++) {
    c3_d_ytemp[c3_i16] = c3_ytemp[c3_i16];
  }

  c3_filter(chartInstance, c3_B, c3_d_ytemp, c3_outBuff, c3_ytemp);
  for (c3_i17 = 0; c3_i17 < 128; c3_i17++) {
    c3_y[c3_i17] = c3_ytemp[133 - c3_i17];
  }
}

static void c3_introsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp, int32_T c3_b_x[4])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_c_introsort(chartInstance, c3_b_x, c3_cmp);
}

static void c3_insertionsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp, int32_T c3_b_x[4])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_d_insertionsort(chartInstance, c3_b_x, c3_cmp);
}

static void c3_check_forloop_overflow_error(SFc3_untitledInstanceStruct
  *chartInstance, const emlrtStack *c3_sp)
{
  static char_T c3_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c3_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 34), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c3_sp, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
              (c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c3_sp, NULL,
    "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
}

static void c3_warning(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp)
{
  static char_T c3_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c3_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c3_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 7), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_msgID, 10, 0U, 1, 0U, 2, 1, 21),
                false);
  c3_st.site = &c3_r_emlrtRSI;
  c3_b_feval(chartInstance, &c3_st, c3_y, c3_feval(chartInstance, &c3_st, c3_b_y,
              c3_c_y));
}

static void c3_filter(SFc3_untitledInstanceStruct *chartInstance, real_T c3_b[3],
                      real_T c3_x[140], real_T c3_zi[2], real_T c3_y[140])
{
  real_T c3_as;
  int32_T c3_a;
  int32_T c3_b_a;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_c_j;
  int32_T c3_c_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_naxpy;
  (void)chartInstance;
  for (c3_k = 0; c3_k < 2; c3_k++) {
    c3_b_k = c3_k;
    c3_y[c3_b_k] = c3_zi[c3_b_k];
  }

  memset(&c3_y[2], 0, 138U * sizeof(real_T));
  for (c3_c_k = 0; c3_c_k < 140; c3_c_k++) {
    c3_b_k = c3_c_k;
    c3_a = 140 - c3_b_k;
    if (c3_a < 3) {
      c3_naxpy = c3_a;
    } else {
      c3_naxpy = 3;
    }

    c3_as = c3_x[c3_b_k];
    c3_i = (uint8_T)c3_naxpy;
    for (c3_j = 0; c3_j < c3_i; c3_j++) {
      c3_b_j = c3_j;
      c3_y[c3_b_k + c3_b_j] += c3_as * c3_b[c3_b_j];
    }

    c3_b_a = 139 - c3_b_k;
    if (c3_b_a < 2) {
      c3_naxpy = c3_b_a;
    } else {
      c3_naxpy = 2;
    }

    c3_as = -c3_y[c3_b_k];
    c3_i1 = (uint8_T)c3_naxpy;
    for (c3_c_j = 0; c3_c_j < c3_i1; c3_c_j++) {
      c3_b_j = c3_c_j + 1;
      c3_y[c3_b_k + c3_b_j] += c3_as * 0.0;
    }
  }
}

static void c3_pivot(SFc3_untitledInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_v[128], int32_T c3_ip, int32_T
                     c3_ia, int32_T c3_ib, real_T c3_b_v[128], int32_T *c3_b_ip,
                     int32_T *c3_reps)
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 128; c3_i++) {
    c3_b_v[c3_i] = c3_v[c3_i];
  }

  *c3_b_ip = c3_ip;
  *c3_reps = c3_b_pivot(chartInstance, c3_sp, c3_b_v, c3_b_ip, c3_ia, c3_ib);
}

static void c3_medmed(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
                      [128], int32_T c3_nv, int32_T c3_ia, real_T c3_b_v[128])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 128; c3_i++) {
    c3_b_v[c3_i] = c3_v[c3_i];
  }

  c3_b_medmed(chartInstance, c3_b_v, c3_nv, c3_ia);
}

static int32_T c3_thirdOfFive(SFc3_untitledInstanceStruct *chartInstance, real_T
  c3_v[128], int32_T c3_ia, int32_T c3_ib)
{
  real_T c3_a;
  real_T c3_ab_a;
  real_T c3_ab_b;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_v1;
  real_T c3_b_v2;
  real_T c3_b_v3;
  real_T c3_bb_a;
  real_T c3_bb_b;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_v1;
  real_T c3_c_v2;
  real_T c3_c_v3;
  real_T c3_cb_a;
  real_T c3_cb_b;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_db_a;
  real_T c3_db_b;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_eb_a;
  real_T c3_eb_b;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_l_a;
  real_T c3_l_b;
  real_T c3_m_a;
  real_T c3_m_b;
  real_T c3_n_a;
  real_T c3_n_b;
  real_T c3_o_a;
  real_T c3_o_b;
  real_T c3_p_a;
  real_T c3_p_b;
  real_T c3_q_a;
  real_T c3_q_b;
  real_T c3_r_a;
  real_T c3_r_b;
  real_T c3_s_a;
  real_T c3_s_b;
  real_T c3_t_a;
  real_T c3_t_b;
  real_T c3_u_a;
  real_T c3_u_b;
  real_T c3_v1;
  real_T c3_v2;
  real_T c3_v3;
  real_T c3_v4;
  real_T c3_v5;
  real_T c3_v_a;
  real_T c3_v_b;
  real_T c3_w_a;
  real_T c3_w_b;
  real_T c3_x_a;
  real_T c3_x_b;
  real_T c3_y_a;
  real_T c3_y_b;
  int32_T c3_b_i1;
  int32_T c3_b_i2;
  int32_T c3_b_i3;
  int32_T c3_b_im;
  int32_T c3_c_i2;
  int32_T c3_c_i3;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_im;
  int32_T c3_j1;
  int32_T c3_j2;
  int32_T c3_j3;
  int32_T c3_j4;
  int32_T c3_j5;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_f_p;
  boolean_T c3_g_p;
  boolean_T c3_h_p;
  boolean_T c3_i_p;
  boolean_T c3_j_p;
  boolean_T c3_k_p;
  boolean_T c3_l_p;
  boolean_T c3_m_p;
  boolean_T c3_n_p;
  boolean_T c3_o_p;
  boolean_T c3_p;
  (void)chartInstance;
  c3_i2 = c3_ia;
  if ((c3_ia == c3_ib) || (c3_i2 + 1 == c3_ib)) {
    c3_im = c3_ia;
  } else {
    c3_i3 = c3_i2 + 2;
    c3_i4 = c3_i3 + 1;
    if ((c3_i3 == c3_ib) || (c3_i4 == c3_ib)) {
      c3_i1 = c3_ia;
      c3_v1 = c3_v[c3_ia - 1];
      c3_b_i2 = c3_i2 + 1;
      c3_v2 = c3_v[c3_i2];
      c3_b_i3 = c3_i3;
      c3_v3 = c3_v[c3_i3 - 1];
      c3_a = c3_v1;
      c3_b = c3_v2;
      c3_c_a = c3_a;
      c3_c_b = c3_b;
      c3_p = (c3_c_a < c3_c_b);
      if (c3_p) {
        c3_f_a = c3_v2;
        c3_f_b = c3_v3;
        c3_j_a = c3_f_a;
        c3_j_b = c3_f_b;
        c3_d_p = (c3_j_a < c3_j_b);
        if (c3_d_p) {
          c3_b_im = c3_b_i2;
        } else {
          c3_n_a = c3_v1;
          c3_n_b = c3_v3;
          c3_r_a = c3_n_a;
          c3_r_b = c3_n_b;
          c3_h_p = (c3_r_a < c3_r_b);
          if (c3_h_p) {
            c3_b_im = c3_b_i3;
          } else {
            c3_b_im = c3_i1;
          }
        }
      } else {
        c3_e_a = c3_v1;
        c3_e_b = c3_v3;
        c3_i_a = c3_e_a;
        c3_i_b = c3_e_b;
        c3_c_p = (c3_i_a < c3_i_b);
        if (c3_c_p) {
          c3_b_im = c3_i1;
        } else {
          c3_m_a = c3_v2;
          c3_m_b = c3_v3;
          c3_q_a = c3_m_a;
          c3_q_b = c3_m_b;
          c3_g_p = (c3_q_a < c3_q_b);
          if (c3_g_p) {
            c3_b_im = c3_b_i3;
          } else {
            c3_b_im = c3_b_i2;
          }
        }
      }

      c3_im = c3_b_im;
    } else {
      c3_i5 = c3_i4;
      c3_b_i1 = c3_ia;
      c3_b_v1 = c3_v[c3_ia - 1];
      c3_c_i2 = c3_i2 + 1;
      c3_b_v2 = c3_v[c3_i2];
      c3_c_i3 = c3_i3;
      c3_b_v3 = c3_v[c3_i3 - 1];
      c3_b_a = c3_b_v1;
      c3_b_b = c3_b_v2;
      c3_d_a = c3_b_a;
      c3_d_b = c3_b_b;
      c3_b_p = (c3_d_a < c3_d_b);
      if (c3_b_p) {
        c3_h_a = c3_b_v2;
        c3_h_b = c3_b_v3;
        c3_l_a = c3_h_a;
        c3_l_b = c3_h_b;
        c3_f_p = (c3_l_a < c3_l_b);
        if (c3_f_p) {
          c3_j1 = c3_b_i1;
          c3_j2 = c3_c_i2;
          c3_j3 = c3_c_i3;
        } else {
          c3_p_a = c3_b_v1;
          c3_p_b = c3_b_v3;
          c3_t_a = c3_p_a;
          c3_t_b = c3_p_b;
          c3_j_p = (c3_t_a < c3_t_b);
          if (c3_j_p) {
            c3_j1 = c3_b_i1;
            c3_j2 = c3_c_i3;
            c3_j3 = c3_c_i2;
          } else {
            c3_j1 = c3_c_i3;
            c3_j2 = c3_b_i1;
            c3_j3 = c3_c_i2;
          }
        }
      } else {
        c3_g_a = c3_b_v1;
        c3_g_b = c3_b_v3;
        c3_k_a = c3_g_a;
        c3_k_b = c3_g_b;
        c3_e_p = (c3_k_a < c3_k_b);
        if (c3_e_p) {
          c3_j1 = c3_c_i2;
          c3_j2 = c3_b_i1;
          c3_j3 = c3_c_i3;
        } else {
          c3_o_a = c3_b_v2;
          c3_o_b = c3_b_v3;
          c3_s_a = c3_o_a;
          c3_s_b = c3_o_b;
          c3_i_p = (c3_s_a < c3_s_b);
          if (c3_i_p) {
            c3_j1 = c3_c_i2;
            c3_j2 = c3_c_i3;
            c3_j3 = c3_b_i1;
          } else {
            c3_j1 = c3_c_i3;
            c3_j2 = c3_c_i2;
            c3_j3 = c3_b_i1;
          }
        }
      }

      c3_j4 = c3_i4;
      c3_j5 = c3_i5 + 1;
      c3_c_v1 = c3_v[c3_j1 - 1];
      c3_c_v2 = c3_v[c3_j2 - 1];
      c3_c_v3 = c3_v[c3_j3 - 1];
      c3_v4 = c3_v[c3_i4 - 1];
      c3_v5 = c3_v[c3_i5];
      c3_u_a = c3_v5;
      c3_u_b = c3_v4;
      c3_v_a = c3_u_a;
      c3_v_b = c3_u_b;
      c3_k_p = (c3_v_a < c3_v_b);
      if (c3_k_p) {
        c3_j4 = c3_i5 + 1;
        c3_j5 = c3_i4;
        c3_v5 = c3_v4;
        c3_v4 = c3_v[c3_i5];
      }

      c3_w_a = c3_v5;
      c3_w_b = c3_c_v1;
      c3_x_a = c3_w_a;
      c3_x_b = c3_w_b;
      c3_l_p = (c3_x_a < c3_x_b);
      if (c3_l_p) {
        c3_im = c3_j1;
      } else {
        c3_y_a = c3_v5;
        c3_y_b = c3_c_v2;
        c3_ab_a = c3_y_a;
        c3_ab_b = c3_y_b;
        c3_m_p = (c3_ab_a < c3_ab_b);
        if (c3_m_p) {
          c3_im = c3_j5;
        } else {
          c3_bb_a = c3_v4;
          c3_bb_b = c3_c_v2;
          c3_cb_a = c3_bb_a;
          c3_cb_b = c3_bb_b;
          c3_n_p = (c3_cb_a < c3_cb_b);
          if (c3_n_p) {
            c3_im = c3_j2;
          } else {
            c3_db_a = c3_v4;
            c3_db_b = c3_c_v3;
            c3_eb_a = c3_db_a;
            c3_eb_b = c3_db_b;
            c3_o_p = (c3_eb_a < c3_eb_b);
            if (c3_o_p) {
              c3_im = c3_j4;
            } else {
              c3_im = c3_j3;
            }
          }
        }
      }
    }
  }

  return c3_im;
}

static void c3_med3(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v[128],
                    int32_T c3_nv, int32_T c3_ia, int32_T c3_ib, real_T c3_b_v
                    [128])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 128; c3_i++) {
    c3_b_v[c3_i] = c3_v[c3_i];
  }

  c3_b_med3(chartInstance, c3_b_v, c3_nv, c3_ia, c3_ib);
}

static void c3_findpeaks(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_Yin[128], real_T c3_varargin_2, real_T
  c3_Ypk_data[], int32_T c3_Ypk_size[1], real_T c3_Xpk_data[], int32_T
  c3_Xpk_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_st;
  real_T c3_b_locs_temp_data[256];
  real_T c3_locs_temp_data[256];
  real_T c3_pks_data[256];
  real_T c3_dv[2];
  real_T c3_a;
  real_T c3_b_a;
  real_T c3_b_jj;
  real_T c3_b_minH;
  real_T c3_b_varargin_2;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_base;
  real_T c3_c_a;
  real_T c3_c_varargin_2;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d_b;
  real_T c3_d_i;
  real_T c3_d_varargin_2;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_e_varargin_2;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_f_x;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_i_b;
  real_T c3_i_x;
  real_T c3_j_b;
  real_T c3_k_b;
  real_T c3_minH;
  real_T c3_pk;
  real_T c3_varargin_1;
  real_T c3_x;
  real_T c3_y;
  real_T c3_yk;
  real_T c3_ykfirst;
  int32_T c3_c_data[256];
  int32_T c3_iPk_data[256];
  int32_T c3_sortIdx_data[256];
  int32_T c3_b_iPk_data[128];
  int32_T c3_fPk_data[128];
  int32_T c3_iFinite_data[128];
  int32_T c3_iInfinite_data[128];
  int32_T c3_iv[2];
  int32_T c3_b_iPk_size[1];
  int32_T c3_b_locs_temp_size[1];
  int32_T c3_c_size[1];
  int32_T c3_fPk_size[1];
  int32_T c3_iFinite_size[1];
  int32_T c3_iInfinite_size[1];
  int32_T c3_iPk_size[1];
  int32_T c3_idelete_size[1];
  int32_T c3_iv1[1];
  int32_T c3_locs_temp_size[1];
  int32_T c3_pks_size[1];
  int32_T c3_sortIdx_size[1];
  int32_T c3_b_i;
  int32_T c3_b_i2;
  int32_T c3_b_idx1;
  int32_T c3_b_idx2;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_n;
  int32_T c3_b_nPk;
  int32_T c3_b_varargin_1;
  int32_T c3_c;
  int32_T c3_c_i;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_c_p;
  int32_T c3_c_varargin_1;
  int32_T c3_d_a;
  int32_T c3_d_k;
  int32_T c3_d_loop_ub;
  int32_T c3_d_varargin_1;
  int32_T c3_e_i;
  int32_T c3_e_k;
  int32_T c3_e_loop_ub;
  int32_T c3_e_varargin_1;
  int32_T c3_end;
  int32_T c3_f_i;
  int32_T c3_f_k;
  int32_T c3_f_loop_ub;
  int32_T c3_g_loop_ub;
  int32_T c3_h_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i_loop_ub;
  int32_T c3_idx1;
  int32_T c3_idx2;
  int32_T c3_j;
  int32_T c3_j_loop_ub;
  int32_T c3_jj;
  int32_T c3_k;
  int32_T c3_kEnd;
  int32_T c3_kfirst;
  int32_T c3_locs_temp;
  int32_T c3_loop_ub;
  int32_T c3_n;
  int32_T c3_nInf;
  int32_T c3_nInflect;
  int32_T c3_nPk;
  int32_T c3_np1;
  int32_T c3_pEnd;
  int32_T c3_partialTrueCount;
  int32_T c3_q;
  int32_T c3_qEnd;
  int32_T c3_trueCount;
  char_T c3_dir;
  char_T c3_previousdir;
  boolean_T c3_idelete_data[256];
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b2;
  boolean_T c3_b3;
  boolean_T c3_b4;
  boolean_T c3_b5;
  boolean_T c3_b6;
  boolean_T c3_b7;
  boolean_T c3_b8;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_c_b;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_f_p;
  boolean_T c3_g_p;
  boolean_T c3_h_b;
  boolean_T c3_isinfyk;
  boolean_T c3_isinfykfirst;
  boolean_T c3_l_b;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_ab_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_b_varargin_2 = c3_varargin_2;
  c3_c_varargin_2 = c3_b_varargin_2;
  c3_d_varargin_2 = c3_c_varargin_2;
  c3_minH = c3_d_varargin_2;
  c3_st.site = &c3_bb_emlrtRSI;
  c3_nPk = 0;
  c3_nInf = 0;
  c3_nInflect = 0;
  c3_dir = 'n';
  c3_kfirst = 0;
  c3_ykfirst = rtInf;
  c3_isinfykfirst = true;
  for (c3_k = 0; c3_k < 128; c3_k++) {
    c3_yk = c3_Yin[c3_k];
    c3_x = c3_yk;
    c3_b_b = muDoubleScalarIsNaN(c3_x);
    if (c3_b_b) {
      c3_yk = rtInf;
      c3_isinfyk = true;
    } else {
      c3_b_x = c3_yk;
      c3_c_b = muDoubleScalarIsInf(c3_b_x);
      if (c3_c_b && (c3_yk > 0.0)) {
        c3_isinfyk = true;
        c3_nInf++;
        if ((c3_nInf < 1) || (c3_nInf > 128)) {
          emlrtDynamicBoundsCheckR2012b(c3_nInf, 1, 128, &c3_j_emlrtBCI, &c3_st);
        }

        c3_iInfinite_data[c3_nInf - 1] = c3_k + 1;
      } else {
        c3_isinfyk = false;
      }
    }

    if (c3_yk != c3_ykfirst) {
      c3_previousdir = c3_dir;
      if (c3_isinfyk || c3_isinfykfirst) {
        c3_dir = 'n';
        if (c3_kfirst >= 1) {
          c3_nInflect++;
          if ((c3_nInflect < 1) || (c3_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c3_nInflect, 1, 128, &c3_p_emlrtBCI,
              &c3_st);
          }

          c3_fPk_data[c3_nInflect - 1] = c3_kfirst;
        }
      } else if (c3_yk < c3_ykfirst) {
        c3_dir = 'd';
        if (c3_previousdir != 'd') {
          c3_nInflect++;
          if ((c3_nInflect < 1) || (c3_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c3_nInflect, 1, 128, &c3_o_emlrtBCI,
              &c3_st);
          }

          c3_fPk_data[c3_nInflect - 1] = c3_kfirst;
          if (c3_previousdir == 'i') {
            c3_nPk++;
            if ((c3_nPk < 1) || (c3_nPk > 128)) {
              emlrtDynamicBoundsCheckR2012b(c3_nPk, 1, 128, &c3_l_emlrtBCI,
                &c3_st);
            }

            c3_iFinite_data[c3_nPk - 1] = c3_kfirst;
          }
        }
      } else {
        c3_dir = 'i';
        if (c3_previousdir != 'i') {
          c3_nInflect++;
          if ((c3_nInflect < 1) || (c3_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c3_nInflect, 1, 128, &c3_n_emlrtBCI,
              &c3_st);
          }

          c3_fPk_data[c3_nInflect - 1] = c3_kfirst;
        }
      }

      c3_ykfirst = c3_yk;
      c3_kfirst = c3_k + 1;
      c3_isinfykfirst = c3_isinfyk;
    }
  }

  if ((!c3_isinfykfirst) && ((c3_nInflect == 0) || (c3_fPk_data[c3_nInflect - 1]
        < 128))) {
    c3_nInflect++;
    if ((c3_nInflect < 1) || (c3_nInflect > 128)) {
      emlrtDynamicBoundsCheckR2012b(c3_nInflect, 1, 128, &c3_m_emlrtBCI, &c3_st);
    }
  }

  c3_b = (c3_nPk < 1);
  if (c3_b) {
    c3_i = -1;
  } else {
    if ((c3_nPk < 1) || (c3_nPk > 128)) {
      emlrtDynamicBoundsCheckR2012b(c3_nPk, 1, 128, &c3_k_emlrtBCI, &c3_st);
    }

    c3_i = c3_nPk - 1;
  }

  c3_iFinite_size[0] = c3_i + 1;
  c3_b1 = (c3_nInf < 1);
  if (c3_b1) {
    c3_i1 = -1;
  } else {
    if ((c3_nInf < 1) || (c3_nInf > 128)) {
      emlrtDynamicBoundsCheckR2012b(c3_nInf, 1, 128, &c3_i_emlrtBCI, &c3_st);
    }

    c3_i1 = c3_nInf - 1;
  }

  c3_iInfinite_size[0] = c3_i1 + 1;
  c3_b2 = (c3_nInflect < 1);
  if ((!c3_b2) && ((c3_nInflect < 1) || (c3_nInflect > 128))) {
    emlrtDynamicBoundsCheckR2012b(c3_nInflect, 1, 128, &c3_h_emlrtBCI, &c3_st);
  }

  c3_st.site = &c3_cb_emlrtRSI;
  c3_b_minH = c3_minH;
  c3_iPk_size[0] = c3_iFinite_size[0];
  c3_b_nPk = 0;
  c3_n = c3_iFinite_size[0];
  c3_i2 = (uint8_T)c3_n;
  for (c3_b_k = 0; c3_b_k < c3_i2; c3_b_k++) {
    c3_c_k = c3_b_k;
    c3_i3 = c3_c_k + 1;
    if ((c3_i3 < 1) || (c3_i3 > c3_iFinite_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i3, 1, c3_iFinite_size[0], &c3_s_emlrtBCI,
        &c3_st);
    }

    c3_j = c3_iFinite_data[c3_i3 - 1];
    if ((c3_j < 1) || (c3_j > 128)) {
      emlrtDynamicBoundsCheckR2012b(c3_j, 1, 128, &c3_t_emlrtBCI, &c3_st);
    }

    c3_pk = c3_Yin[c3_j - 1];
    if (c3_pk > c3_b_minH) {
      c3_i6 = c3_j - 1;
      if ((c3_i6 < 1) || (c3_i6 > 128)) {
        emlrtDynamicBoundsCheckR2012b(c3_i6, 1, 128, &c3_u_emlrtBCI, &c3_st);
      }

      c3_varargin_1 = c3_Yin[c3_i6 - 1];
      c3_i8 = c3_j + 1;
      if ((c3_i8 < 1) || (c3_i8 > 128)) {
        emlrtDynamicBoundsCheckR2012b(c3_i8, 1, 128, &c3_v_emlrtBCI, &c3_st);
      }

      c3_e_varargin_2 = c3_Yin[c3_i8 - 1];
      c3_c_x = c3_varargin_1;
      c3_y = c3_e_varargin_2;
      c3_d_x = c3_c_x;
      c3_b_y = c3_y;
      c3_e_x = c3_d_x;
      c3_c_y = c3_b_y;
      c3_a = c3_e_x;
      c3_d_b = c3_c_y;
      c3_f_x = c3_a;
      c3_d_y = c3_d_b;
      c3_g_x = c3_f_x;
      c3_e_y = c3_d_y;
      c3_base = muDoubleScalarMax(c3_g_x, c3_e_y);
      if (c3_pk - c3_base >= 0.0) {
        c3_b_nPk++;
        if ((c3_b_nPk < 1) || (c3_b_nPk > c3_iPk_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_b_nPk, 1, c3_iPk_size[0],
            &c3_w_emlrtBCI, &c3_st);
        }

        c3_b_iPk_data[c3_b_nPk - 1] = c3_j;
      }
    }
  }

  c3_b3 = (c3_b_nPk < 1);
  if (c3_b3) {
    c3_i4 = 0;
  } else {
    if (c3_iPk_size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c3_iPk_size[0], &c3_g_emlrtBCI, &c3_st);
    }

    if ((c3_b_nPk < 1) || (c3_b_nPk > c3_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_b_nPk, 1, c3_iPk_size[0], &c3_f_emlrtBCI,
        &c3_st);
    }

    c3_i4 = c3_b_nPk;
  }

  c3_iPk_size[0] = c3_i4;
  c3_b_iPk_size[0] = c3_iPk_size[0];
  c3_loop_ub = c3_iPk_size[0] - 1;
  for (c3_i5 = 0; c3_i5 <= c3_loop_ub; c3_i5++) {
    c3_iPk_data[c3_i5] = c3_b_iPk_data[c3_i5];
  }

  c3_st.site = &c3_db_emlrtRSI;
  c3_iPk_size[0] = c3_b_iPk_size[0];
  c3_b_loop_ub = c3_b_iPk_size[0] - 1;
  for (c3_i7 = 0; c3_i7 <= c3_b_loop_ub; c3_i7++) {
    c3_b_iPk_data[c3_i7] = c3_iPk_data[c3_i7];
  }

  c3_b_st.site = &c3_hb_emlrtRSI;
  c3_c_st.site = &c3_ib_emlrtRSI;
  c3_d_st.site = &c3_jb_emlrtRSI;
  c3_do_vectors(chartInstance, &c3_d_st, c3_b_iPk_data, c3_iPk_size,
                c3_iInfinite_data, c3_iInfinite_size, c3_c_data, c3_c_size,
                c3_fPk_data, c3_fPk_size, c3_iFinite_data, c3_iFinite_size);
  c3_st.site = &c3_eb_emlrtRSI;
  if (c3_c_size[0] == 0) {
    c3_b_st.site = &c3_kb_emlrtRSI;
    c3_c_st.site = &c3_mb_emlrtRSI;
    c3_b_iPk_size[0] = 0;
  } else {
    c3_pks_size[0] = c3_c_size[0];
    c3_c_loop_ub = c3_c_size[0] - 1;
    for (c3_i9 = 0; c3_i9 <= c3_c_loop_ub; c3_i9++) {
      c3_pks_data[c3_i9] = c3_Yin[c3_c_data[c3_i9] - 1];
    }

    c3_locs_temp_size[0] = c3_c_size[0];
    c3_d_loop_ub = c3_c_size[0] - 1;
    for (c3_i10 = 0; c3_i10 <= c3_d_loop_ub; c3_i10++) {
      c3_locs_temp_data[c3_i10] = 1.0 + (real_T)(c3_c_data[c3_i10] - 1);
    }

    c3_sortIdx_size[0] = c3_pks_size[0];
    c3_b_n = c3_pks_size[0];
    c3_np1 = c3_b_n + 1;
    c3_i11 = c3_b_n;
    for (c3_d_k = 1; c3_d_k <= c3_i11 - 1; c3_d_k += 2) {
      c3_idx1 = c3_d_k - 1;
      c3_idx2 = c3_d_k;
      c3_b_a = c3_pks_data[c3_idx1];
      c3_e_b = c3_pks_data[c3_idx2];
      c3_c_a = c3_b_a;
      c3_f_b = c3_e_b;
      c3_e_a = c3_c_a;
      c3_g_b = c3_f_b;
      c3_p = (c3_e_a >= c3_g_b);
      if (c3_p) {
        c3_b_p = true;
      } else {
        c3_h_x = c3_c_a;
        c3_h_b = muDoubleScalarIsNaN(c3_h_x);
        if (c3_h_b) {
          c3_b_p = true;
        } else {
          c3_b_p = false;
        }
      }

      c3_d_p = c3_b_p;
      if (c3_d_p) {
        c3_sortIdx_data[c3_d_k - 1] = c3_d_k;
        c3_sortIdx_data[c3_d_k] = c3_d_k + 1;
      } else {
        c3_sortIdx_data[c3_d_k - 1] = c3_d_k + 1;
        c3_sortIdx_data[c3_d_k] = c3_d_k;
      }
    }

    if ((c3_b_n & 1) != 0) {
      c3_sortIdx_data[c3_b_n - 1] = c3_b_n;
    }

    c3_b_i = 2;
    while (c3_b_i < c3_b_n) {
      c3_d_a = c3_b_i;
      c3_b_i2 = c3_d_a << 1;
      c3_b_j = 1;
      for (c3_pEnd = 1 + c3_b_i; c3_pEnd < c3_np1; c3_pEnd = c3_qEnd + c3_b_i) {
        c3_c_p = c3_b_j - 1;
        c3_q = c3_pEnd - 1;
        c3_qEnd = c3_b_j + c3_b_i2;
        if (c3_qEnd > c3_np1) {
          c3_qEnd = c3_np1;
        }

        c3_e_k = 0;
        c3_kEnd = c3_qEnd - c3_b_j;
        while (c3_e_k + 1 <= c3_kEnd) {
          c3_b_idx1 = c3_sortIdx_data[c3_c_p] - 1;
          c3_b_idx2 = c3_sortIdx_data[c3_q] - 1;
          c3_f_a = c3_pks_data[c3_b_idx1];
          c3_i_b = c3_pks_data[c3_b_idx2];
          c3_g_a = c3_f_a;
          c3_j_b = c3_i_b;
          c3_h_a = c3_g_a;
          c3_k_b = c3_j_b;
          c3_e_p = (c3_h_a >= c3_k_b);
          if (c3_e_p) {
            c3_f_p = true;
          } else {
            c3_i_x = c3_g_a;
            c3_l_b = muDoubleScalarIsNaN(c3_i_x);
            if (c3_l_b) {
              c3_f_p = true;
            } else {
              c3_f_p = false;
            }
          }

          c3_g_p = c3_f_p;
          if (c3_g_p) {
            c3_iPk_data[c3_e_k] = c3_sortIdx_data[c3_c_p];
            c3_c_p++;
            if (c3_c_p + 1 == c3_pEnd) {
              while (c3_q + 1 < c3_qEnd) {
                c3_e_k++;
                c3_iPk_data[c3_e_k] = c3_sortIdx_data[c3_q];
                c3_q++;
              }
            }
          } else {
            c3_iPk_data[c3_e_k] = c3_sortIdx_data[c3_q];
            c3_q++;
            if (c3_q + 1 == c3_qEnd) {
              while (c3_c_p + 1 < c3_pEnd) {
                c3_e_k++;
                c3_iPk_data[c3_e_k] = c3_sortIdx_data[c3_c_p];
                c3_c_p++;
              }
            }
          }

          c3_e_k++;
        }

        c3_c_p = c3_b_j - 2;
        for (c3_f_k = 0; c3_f_k < c3_kEnd; c3_f_k++) {
          c3_e_k = c3_f_k;
          c3_sortIdx_data[(c3_c_p + c3_e_k) + 1] = c3_iPk_data[c3_e_k];
        }

        c3_b_j = c3_qEnd;
      }

      c3_b_i = c3_b_i2;
    }

    c3_locs_temp = c3_locs_temp_size[0];
    c3_b_locs_temp_size[0] = c3_sortIdx_size[0];
    c3_f_loop_ub = c3_sortIdx_size[0] - 1;
    for (c3_i16 = 0; c3_i16 <= c3_f_loop_ub; c3_i16++) {
      if ((c3_sortIdx_data[c3_i16] < 1) || (c3_sortIdx_data[c3_i16] >
           c3_locs_temp)) {
        emlrtDynamicBoundsCheckR2012b(c3_sortIdx_data[c3_i16], 1, c3_locs_temp,
          &c3_x_emlrtBCI, &c3_st);
      }

      c3_b_locs_temp_data[c3_i16] = c3_locs_temp_data[c3_sortIdx_data[c3_i16] -
        1];
    }

    c3_locs_temp_size[0] = c3_b_locs_temp_size[0];
    c3_h_loop_ub = c3_b_locs_temp_size[0] - 1;
    for (c3_i18 = 0; c3_i18 <= c3_h_loop_ub; c3_i18++) {
      c3_locs_temp_data[c3_i18] = c3_b_locs_temp_data[c3_i18];
    }

    c3_dv[0] = (real_T)c3_locs_temp_size[0];
    c3_idelete_size[0] = (int32_T)c3_dv[0];
    c3_j_loop_ub = (int32_T)c3_dv[0] - 1;
    if (c3_j_loop_ub >= 0) {
      memset(&c3_idelete_data[0], 0, (uint32_T)(c3_j_loop_ub + 1) * sizeof
             (boolean_T));
    }

    c3_iv1[0] = (int32_T)c3_dv[0];
    c3_b_varargin_1 = c3_iv1[0];
    c3_c_varargin_1 = c3_b_varargin_1;
    c3_d1 = (real_T)c3_c_varargin_1;
    c3_i20 = (int32_T)c3_d1;
    for (c3_c_i = 0; c3_c_i < c3_i20; c3_c_i++) {
      c3_d_i = (real_T)c3_c_i + 1.0;
      c3_i21 = (int32_T)c3_d_i;
      if ((c3_i21 < 1) || (c3_i21 > c3_idelete_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i21, 1, c3_idelete_size[0],
          &c3_ab_emlrtBCI, &c3_st);
      }

      if (!c3_idelete_data[c3_i21 - 1]) {
        c3_d_varargin_1 = c3_idelete_size[0];
        c3_e_varargin_1 = c3_d_varargin_1;
        c3_d2 = (real_T)c3_e_varargin_1;
        c3_i22 = (int32_T)-((-1.0 - c3_d2) + 1.0);
        emlrtForLoopVectorCheckR2021a(c3_d2, -1.0, 1.0, mxDOUBLE_CLASS, c3_i22,
          &c3_rb_emlrtRTEI, &c3_st);
        for (c3_jj = 0; c3_jj < c3_i22; c3_jj++) {
          c3_b_jj = c3_d2 - (real_T)c3_jj;
          c3_i26 = (int32_T)c3_b_jj;
          if ((c3_i26 < 1) || (c3_i26 > c3_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i26, 1, c3_idelete_size[0],
              &c3_db_emlrtBCI, &c3_st);
          }

          c3_b5 = c3_idelete_data[c3_i26 - 1];
          c3_i27 = (int32_T)c3_b_jj;
          if ((c3_i27 < 1) || (c3_i27 > c3_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i27, 1, c3_locs_temp_size[0],
              &c3_eb_emlrtBCI, &c3_st);
          }

          c3_i28 = (int32_T)c3_d_i;
          if ((c3_i28 < 1) || (c3_i28 > c3_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i28, 1, c3_locs_temp_size[0],
              &c3_fb_emlrtBCI, &c3_st);
          }

          c3_b6 = (c3_locs_temp_data[c3_i27 - 1] >= c3_locs_temp_data[c3_i28 - 1]
                   - 31.0);
          c3_i29 = (int32_T)c3_b_jj;
          if ((c3_i29 < 1) || (c3_i29 > c3_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i29, 1, c3_locs_temp_size[0],
              &c3_gb_emlrtBCI, &c3_st);
          }

          c3_i30 = (int32_T)c3_d_i;
          if ((c3_i30 < 1) || (c3_i30 > c3_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i30, 1, c3_locs_temp_size[0],
              &c3_hb_emlrtBCI, &c3_st);
          }

          c3_b7 = (c3_locs_temp_data[c3_i29 - 1] <= c3_locs_temp_data[c3_i30 - 1]
                   + 31.0);
          c3_b8 = (c3_b6 && c3_b7);
          c3_i31 = (int32_T)c3_b_jj;
          if ((c3_i31 < 1) || (c3_i31 > c3_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i31, 1, c3_idelete_size[0],
              &c3_ib_emlrtBCI, &c3_st);
          }

          c3_idelete_data[c3_i31 - 1] = (c3_b5 || c3_b8);
        }

        c3_i25 = (int32_T)c3_d_i;
        if ((c3_i25 < 1) || (c3_i25 > c3_idelete_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i25, 1, c3_idelete_size[0],
            &c3_cb_emlrtBCI, &c3_st);
        }

        c3_idelete_data[c3_i25 - 1] = false;
      }
    }

    c3_end = c3_idelete_size[0];
    c3_trueCount = 0;
    for (c3_e_i = 0; c3_e_i < c3_end; c3_e_i++) {
      if (!c3_idelete_data[c3_e_i]) {
        c3_trueCount++;
      }
    }

    c3_b_iPk_size[0] = c3_trueCount;
    c3_partialTrueCount = 0;
    for (c3_f_i = 0; c3_f_i < c3_end; c3_f_i++) {
      if (!c3_idelete_data[c3_f_i]) {
        c3_i24 = c3_sortIdx_size[0] - 1;
        if ((c3_f_i < 0) || (c3_f_i > c3_i24)) {
          emlrtDynamicBoundsCheckR2012b(c3_f_i, 0, c3_i24, &c3_bb_emlrtBCI,
            &c3_st);
        }

        c3_iPk_data[c3_partialTrueCount] = c3_sortIdx_data[c3_f_i];
        c3_partialTrueCount++;
      }
    }

    if (c3_b_iPk_size[0] == 0) {
    } else {
      c3_i23 = c3_b_iPk_size[0];
      c3_b_st.site = &c3_lb_emlrtRSI;
      c3_d_introsort(chartInstance, &c3_b_st, c3_iPk_data, c3_i23);
    }
  }

  if (c3_b_iPk_size[0] > 128) {
    c3_fPk_size[0] = 128;
    c3_st.site = &c3_fb_emlrtRSI;
    c3_indexShapeCheck(chartInstance);
    c3_b_iPk_size[0] = 128;
  } else {
    c3_dv[0] = (real_T)c3_b_iPk_size[0];
    c3_fPk_size[0] = (int32_T)c3_dv[0];
  }

  c3_d = (real_T)c3_fPk_size[0];
  c3_b4 = (c3_d < 1.0);
  if (c3_b4) {
    c3_i13 = 0;
  } else {
    c3_i12 = 1;
    if ((c3_i12 < 1) || (c3_i12 > c3_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i12, 1, c3_b_iPk_size[0], &c3_r_emlrtBCI,
        (emlrtConstCTX)c3_sp);
    }

    c3_i14 = (int32_T)c3_d;
    if ((c3_i14 < 1) || (c3_i14 > c3_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i14, 1, c3_b_iPk_size[0], &c3_q_emlrtBCI,
        (emlrtConstCTX)c3_sp);
    }

    c3_i13 = c3_i14;
  }

  c3_iv[0] = 1;
  c3_iv[1] = c3_i13;
  c3_st.site = &c3_gb_emlrtRSI;
  c3_b_indexShapeCheck(chartInstance, &c3_st, c3_b_iPk_size[0], c3_iv);
  c3_c = c3_c_size[0];
  c3_fPk_size[0] = c3_i13;
  c3_e_loop_ub = c3_i13 - 1;
  for (c3_i15 = 0; c3_i15 <= c3_e_loop_ub; c3_i15++) {
    if ((c3_iPk_data[c3_i15] < 1) || (c3_iPk_data[c3_i15] > c3_c)) {
      emlrtDynamicBoundsCheckR2012b(c3_iPk_data[c3_i15], 1, c3_c, &c3_y_emlrtBCI,
        (emlrtConstCTX)c3_sp);
    }

    c3_fPk_data[c3_i15] = c3_c_data[c3_iPk_data[c3_i15] - 1];
  }

  c3_Ypk_size[0] = c3_fPk_size[0];
  c3_g_loop_ub = c3_fPk_size[0] - 1;
  for (c3_i17 = 0; c3_i17 <= c3_g_loop_ub; c3_i17++) {
    c3_Ypk_data[c3_i17] = c3_Yin[c3_fPk_data[c3_i17] - 1];
  }

  c3_Xpk_size[0] = c3_fPk_size[0];
  c3_i_loop_ub = c3_fPk_size[0] - 1;
  for (c3_i19 = 0; c3_i19 <= c3_i_loop_ub; c3_i19++) {
    c3_Xpk_data[c3_i19] = 1.0 + (real_T)(c3_fPk_data[c3_i19] - 1);
  }
}

static void c3_do_vectors(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_a_data[], int32_T c3_a_size[1], int32_T
  c3_b_data[], int32_T c3_b_size[1], int32_T c3_c_data[], int32_T c3_c_size[1],
  int32_T c3_ia_data[], int32_T c3_ia_size[1], int32_T c3_ib_data[], int32_T
  c3_ib_size[1])
{
  static char_T c3_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'A' };

  static char_T c3_cv1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'B' };

  static char_T c3_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_iv[2];
  int32_T c3_a;
  int32_T c3_ab_a;
  int32_T c3_ak;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_ak;
  int32_T c3_b_bk;
  int32_T c3_b_c;
  int32_T c3_b_ialast;
  int32_T c3_b_iblast;
  int32_T c3_b_k;
  int32_T c3_b_nx;
  int32_T c3_b_xkplus;
  int32_T c3_bb_a;
  int32_T c3_bk;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_c;
  int32_T c3_c_ialast;
  int32_T c3_c_iblast;
  int32_T c3_c_k;
  int32_T c3_c_nx;
  int32_T c3_c_xkplus;
  int32_T c3_cb_a;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_d_c;
  int32_T c3_d_k;
  int32_T c3_d_nx;
  int32_T c3_d_xkplus;
  int32_T c3_db_a;
  int32_T c3_e_a;
  int32_T c3_e_b;
  int32_T c3_eb_a;
  int32_T c3_f_a;
  int32_T c3_f_b;
  int32_T c3_fb_a;
  int32_T c3_g_a;
  int32_T c3_g_b;
  int32_T c3_gb_a;
  int32_T c3_h_a;
  int32_T c3_h_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i_a;
  int32_T c3_i_b;
  int32_T c3_iafirst;
  int32_T c3_ialast;
  int32_T c3_ibfirst;
  int32_T c3_iblast;
  int32_T c3_j_a;
  int32_T c3_k;
  int32_T c3_k_a;
  int32_T c3_l_a;
  int32_T c3_m_a;
  int32_T c3_n_a;
  int32_T c3_na;
  int32_T c3_nb;
  int32_T c3_nc;
  int32_T c3_ncmax;
  int32_T c3_nia;
  int32_T c3_nib;
  int32_T c3_nx;
  int32_T c3_o_a;
  int32_T c3_p_a;
  int32_T c3_q_a;
  int32_T c3_r_a;
  int32_T c3_s_a;
  int32_T c3_t_a;
  int32_T c3_u_a;
  int32_T c3_v_a;
  int32_T c3_w_a;
  int32_T c3_x_a;
  int32_T c3_xkplus;
  int32_T c3_y_a;
  boolean_T c3_b1;
  boolean_T c3_b2;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_exitg1;
  boolean_T c3_f_p;
  boolean_T c3_p;
  c3_na = c3_a_size[0];
  c3_nb = c3_b_size[0];
  c3_a = c3_na;
  c3_b = c3_nb;
  c3_ncmax = c3_a + c3_b;
  c3_iv[0] = c3_ncmax;
  c3_c_size[0] = c3_iv[0];
  c3_ia_size[0] = c3_na;
  c3_ib_size[0] = c3_nb;
  if (!c3_issorted(chartInstance, c3_a_data, c3_a_size)) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c3_sp, &c3_c_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 1U, 14, c3_c_y)));
  }

  if (!c3_issorted(chartInstance, c3_b_data, c3_b_size)) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c3_sp, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  c3_nc = -1;
  c3_nia = -1;
  c3_nib = 0;
  c3_iafirst = 1;
  c3_ialast = 1;
  c3_ibfirst = 1;
  c3_iblast = 1;
  while ((c3_ialast <= c3_na) && (c3_iblast <= c3_nb)) {
    c3_k = c3_ialast;
    c3_b_ialast = c3_k;
    c3_nx = c3_a_size[0];
    c3_ak = c3_a_data[c3_b_ialast - 1];
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_b_ialast < c3_nx)) {
      c3_b_a = c3_b_ialast + 1;
      c3_c = c3_b_a - 1;
      c3_xkplus = c3_a_data[c3_c];
      c3_e_a = c3_xkplus;
      c3_c_b = c3_ak;
      c3_p = (c3_e_a == c3_c_b);
      if (c3_p) {
        c3_l_a = c3_b_ialast + 1;
        c3_b_ialast = c3_l_a;
      } else {
        c3_exitg1 = true;
      }
    }

    c3_ialast = c3_b_ialast;
    c3_d_k = c3_iblast;
    c3_c_iblast = c3_d_k;
    c3_d_nx = c3_b_size[0];
    c3_b_bk = c3_b_data[c3_c_iblast - 1];
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_c_iblast < c3_d_nx)) {
      c3_n_a = c3_c_iblast + 1;
      c3_d_c = c3_n_a - 1;
      c3_d_xkplus = c3_b_data[c3_d_c];
      c3_s_a = c3_d_xkplus;
      c3_g_b = c3_b_bk;
      c3_e_p = (c3_s_a == c3_g_b);
      if (c3_e_p) {
        c3_w_a = c3_c_iblast + 1;
        c3_c_iblast = c3_w_a;
      } else {
        c3_exitg1 = true;
      }
    }

    c3_iblast = c3_c_iblast;
    c3_p_a = c3_ak;
    c3_f_b = c3_b_bk;
    c3_d_p = (c3_p_a == c3_f_b);
    if (c3_d_p) {
      c3_u_a = c3_nc + 1;
      c3_nc = c3_u_a;
      c3_c_data[c3_nc] = c3_ak;
      c3_x_a = c3_nia + 1;
      c3_nia = c3_x_a;
      c3_ia_data[c3_nia] = c3_iafirst;
      c3_bb_a = c3_b_ialast + 1;
      c3_ialast = c3_bb_a;
      c3_iafirst = c3_ialast;
      c3_eb_a = c3_c_iblast + 1;
      c3_iblast = c3_eb_a;
      c3_ibfirst = c3_iblast;
    } else {
      c3_t_a = c3_ak;
      c3_h_b = c3_b_bk;
      c3_v_a = c3_t_a;
      c3_i_b = c3_h_b;
      c3_f_p = (c3_v_a < c3_i_b);
      if (c3_f_p) {
        c3_ab_a = c3_nc + 1;
        c3_nc = c3_ab_a;
        c3_db_a = c3_nia + 1;
        c3_nia = c3_db_a;
        c3_c_data[c3_nc] = c3_ak;
        c3_ia_data[c3_nia] = c3_iafirst;
        c3_gb_a = c3_b_ialast + 1;
        c3_ialast = c3_gb_a;
        c3_iafirst = c3_ialast;
      } else {
        c3_y_a = c3_nc + 1;
        c3_nc = c3_y_a;
        c3_cb_a = c3_nib + 1;
        c3_nib = c3_cb_a;
        c3_c_data[c3_nc] = c3_b_bk;
        c3_ib_data[c3_nib - 1] = c3_ibfirst;
        c3_fb_a = c3_c_iblast + 1;
        c3_iblast = c3_fb_a;
        c3_ibfirst = c3_iblast;
      }
    }
  }

  while (c3_ialast <= c3_na) {
    c3_b_k = c3_ialast;
    c3_c_ialast = c3_b_k;
    c3_b_nx = c3_a_size[0];
    c3_b_ak = c3_a_data[c3_c_ialast - 1];
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_c_ialast < c3_b_nx)) {
      c3_d_a = c3_c_ialast + 1;
      c3_b_c = c3_d_a - 1;
      c3_b_xkplus = c3_a_data[c3_b_c];
      c3_i_a = c3_b_xkplus;
      c3_d_b = c3_b_ak;
      c3_b_p = (c3_i_a == c3_d_b);
      if (c3_b_p) {
        c3_o_a = c3_c_ialast + 1;
        c3_c_ialast = c3_o_a;
      } else {
        c3_exitg1 = true;
      }
    }

    c3_c_a = c3_nc + 1;
    c3_nc = c3_c_a;
    c3_h_a = c3_nia + 1;
    c3_nia = c3_h_a;
    c3_c_data[c3_nc] = c3_b_ak;
    c3_ia_data[c3_nia] = c3_iafirst;
    c3_m_a = c3_c_ialast + 1;
    c3_ialast = c3_m_a;
    c3_iafirst = c3_ialast;
  }

  while (c3_iblast <= c3_nb) {
    c3_c_k = c3_iblast;
    c3_b_iblast = c3_c_k;
    c3_c_nx = c3_b_size[0];
    c3_bk = c3_b_data[c3_b_iblast - 1];
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_b_iblast < c3_c_nx)) {
      c3_g_a = c3_b_iblast + 1;
      c3_c_c = c3_g_a - 1;
      c3_c_xkplus = c3_b_data[c3_c_c];
      c3_k_a = c3_c_xkplus;
      c3_e_b = c3_bk;
      c3_c_p = (c3_k_a == c3_e_b);
      if (c3_c_p) {
        c3_r_a = c3_b_iblast + 1;
        c3_b_iblast = c3_r_a;
      } else {
        c3_exitg1 = true;
      }
    }

    c3_f_a = c3_nc + 1;
    c3_nc = c3_f_a;
    c3_j_a = c3_nib + 1;
    c3_nib = c3_j_a;
    c3_c_data[c3_nc] = c3_bk;
    c3_ib_data[c3_nib - 1] = c3_ibfirst;
    c3_q_a = c3_b_iblast + 1;
    c3_iblast = c3_q_a;
    c3_ibfirst = c3_iblast;
  }

  if (c3_na > 0) {
    if (c3_nia + 1 > c3_na) {
      c3_e_y = NULL;
      sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c3_g_y = NULL;
      sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c3_sp, &c3_e_emlrtMCI, "error", 0U, 2U, 14, c3_e_y, 14,
                  sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c3_sp, NULL, "message", 1U, 1U, 14, c3_g_y)));
    }

    c3_b_b = (c3_nia + 1 < 1);
    if (c3_b_b) {
      c3_i = 0;
    } else {
      c3_i = c3_nia + 1;
    }

    c3_ia_size[0] = c3_i;
  }

  if (c3_nb > 0) {
    if (c3_nib > c3_nb) {
      c3_f_y = NULL;
      sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c3_i_y = NULL;
      sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c3_sp, &c3_f_emlrtMCI, "error", 0U, 2U, 14, c3_f_y, 14,
                  sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c3_sp, NULL, "message", 1U, 1U, 14, c3_i_y)));
    }

    c3_b1 = (c3_nib < 1);
    if (c3_b1) {
      c3_i1 = 0;
    } else {
      c3_i1 = c3_nib;
    }

    c3_ib_size[0] = c3_i1;
  }

  if (c3_ncmax > 0) {
    if (c3_nc + 1 > c3_ncmax) {
      c3_h_y = NULL;
      sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c3_j_y = NULL;
      sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c3_sp, &c3_g_emlrtMCI, "error", 0U, 2U, 14, c3_h_y, 14,
                  sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c3_sp, NULL, "message", 1U, 1U, 14, c3_j_y)));
    }

    c3_b2 = (c3_nc + 1 < 1);
    if (c3_b2) {
      c3_i2 = 0;
    } else {
      c3_i2 = c3_nc + 1;
    }

    c3_c_size[0] = c3_i2;
  }
}

static boolean_T c3_issorted(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1])
{
  real_T c3_d;
  real_T c3_d1;
  int32_T c3_subs[2];
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_dim;
  int32_T c3_b_k;
  int32_T c3_b_n;
  int32_T c3_c_dim;
  int32_T c3_c_k;
  int32_T c3_d_dim;
  int32_T c3_dim;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_k;
  int32_T c3_n;
  int32_T c3_nx;
  int32_T c3_varargin_1;
  int32_T c3_x1;
  int32_T c3_x2;
  boolean_T c3_c_b;
  boolean_T c3_exitg1;
  boolean_T c3_exitg2;
  boolean_T c3_y;
  (void)chartInstance;
  c3_y = true;
  c3_dim = 2;
  if (c3_x_size[0] != 1) {
    c3_dim = 1;
  }

  if (c3_dim <= 1) {
    c3_d = (real_T)c3_x_size[0];
  } else {
    c3_d = 1.0;
  }

  c3_nx = (int32_T)c3_d;
  if ((c3_x_size[0] == 0) || (c3_nx == 1)) {
  } else {
    c3_b_dim = c3_dim;
    c3_y = true;
    if (c3_b_dim == 2) {
      c3_n = 0;
    } else {
      c3_n = 1;
    }

    c3_i = (uint8_T)c3_n - 1;
    c3_k = 0;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_k <= c3_i)) {
      c3_c_dim = c3_b_dim;
      c3_y = true;
      if (c3_c_dim == 1) {
        c3_d1 = (real_T)c3_x_size[0];
        c3_b_n = (int32_T)c3_d1 - 1;
      } else {
        c3_b_n = c3_x_size[0];
      }

      c3_i1 = (uint8_T)c3_b_n - 1;
      c3_b_k = 1;
      c3_exitg2 = false;
      while ((!c3_exitg2) && (c3_b_k - 1 <= c3_i1)) {
        c3_c_k = c3_b_k;
        c3_d_dim = c3_c_dim - 1;
        c3_varargin_1 = c3_c_k;
        c3_x1 = c3_x_data[c3_varargin_1 - 1];
        c3_subs[0] = c3_varargin_1;
        c3_subs[1] = 1;
        c3_subs[c3_d_dim]++;
        c3_x2 = c3_x_data[c3_subs[0] - 1];
        c3_subs[0] = c3_x1;
        c3_subs[1] = c3_x2;
        c3_a = c3_subs[0];
        c3_b = c3_subs[1];
        c3_b_a = c3_a;
        c3_b_b = c3_b;
        c3_c_b = (c3_b_a <= c3_b_b);
        c3_y = c3_c_b;
        if (!c3_y) {
          c3_exitg2 = true;
        } else {
          c3_b_k++;
        }
      }

      if (!c3_y) {
        c3_exitg1 = true;
      } else {
        c3_k++;
      }
    }
  }

  return c3_y;
}

static void c3_b_introsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_x_size[1], int32_T c3_xend,
  int32_T c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_d_introsort(chartInstance, c3_sp, c3_b_x_data, c3_xend);
}

static void c3_b_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x_data[], int32_T c3_x_size[1], int32_T c3_xend, int32_T
  c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_e_insertionsort(chartInstance, c3_b_x_data, c3_xend);
}

static void c3_c_insertionsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_x_size[1], int32_T
  c3_xstart, int32_T c3_xend, int32_T c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_f_insertionsort(chartInstance, c3_sp, c3_b_x_data, c3_xstart, c3_xend);
}

static void c3_heapsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1], int32_T c3_xstart, int32_T c3_xend, int32_T
  c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_b_heapsort(chartInstance, c3_b_x_data, c3_xstart, c3_xend);
}

static void c3_heapify(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_x_size[1], int32_T c3_idx, int32_T c3_xstart, int32_T
  c3_xend, int32_T c3_b_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_x_data[c3_i] = c3_x_data[c3_i];
  }

  c3_b_heapify(chartInstance, c3_b_x_data, c3_idx, c3_xstart, c3_xend);
}

static void c3_indexShapeCheck(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_indexShapeCheck(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_matrixSize, int32_T c3_indexSize[2])
{
  static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_size1;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_c;
  boolean_T c3_c;
  boolean_T c3_nonSingletonDimFound;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_size1 = c3_matrixSize;
  if (c3_size1 != 1) {
    c3_b = false;
  } else {
    c3_b = true;
  }

  if (c3_b) {
    c3_nonSingletonDimFound = false;
    if (c3_indexSize[1] != 1) {
      c3_nonSingletonDimFound = true;
    }

    c3_b_b = c3_nonSingletonDimFound;
    if (c3_b_b) {
      c3_c = true;
    } else {
      c3_c = false;
    }
  } else {
    c3_c = false;
  }

  c3_st.site = &c3_wb_emlrtRSI;
  c3_b_c = c3_c;
  if (c3_b_c) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c3_st, &c3_l_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_b_y)));
  }
}

const mxArray *sf_c3_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier, real_T c3_y[128])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_nullptr);
}

static void c3_b_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[128])
{
  real_T c3_dv[128];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 2, 128, 1);
  for (c3_i = 0; c3_i < 128; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_slStringInitializeDynamicBuffers(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c3_feval(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  return c3_m;
}

static void c3_b_feval(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1)
{
  (void)chartInstance;
  sf_mex_call(c3_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
}

static void c3_c_introsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x[4], c3_anonymous_function c3_cmp)
{
  c3_d_insertionsort(chartInstance, c3_x, c3_cmp);
}

static void c3_d_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x[4], c3_anonymous_function c3_cmp)
{
  c3_cell_11 c3_workspace;
  int32_T c3_a[4];
  int32_T c3_b[4];
  int32_T c3_ai;
  int32_T c3_aj;
  int32_T c3_b_i;
  int32_T c3_b_j;
  int32_T c3_c_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_idx;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_varargin_1;
  int32_T c3_varargin_2;
  int32_T c3_xc;
  boolean_T c3_exitg1;
  boolean_T c3_varargout_1;
  (void)chartInstance;
  for (c3_k = 0; c3_k < 3; c3_k++) {
    c3_xc = c3_x[c3_k + 1];
    c3_idx = c3_k;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_idx + 1 >= 1)) {
      c3_varargin_1 = c3_xc;
      c3_varargin_2 = c3_x[c3_idx];
      for (c3_i = 0; c3_i < 4; c3_i++) {
        c3_workspace.f1[c3_i] = c3_cmp.workspace.a[c3_i];
      }

      for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
        c3_workspace.f2[c3_i1] = c3_cmp.workspace.b[c3_i1];
      }

      for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
        c3_a[c3_i2] = c3_workspace.f1[c3_i2];
      }

      for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
        c3_b[c3_i3] = c3_workspace.f2[c3_i3];
      }

      c3_b_i = c3_varargin_1;
      c3_j = c3_varargin_2;
      c3_c_i = c3_b_i - 1;
      c3_b_j = c3_j - 1;
      c3_ai = c3_a[c3_c_i];
      c3_aj = c3_a[c3_b_j];
      if (c3_ai < c3_aj) {
        c3_varargout_1 = true;
      } else if (c3_ai == c3_aj) {
        c3_varargout_1 = (c3_b[c3_c_i] < c3_b[c3_b_j]);
      } else {
        c3_varargout_1 = false;
      }

      if (c3_varargout_1) {
        c3_x[c3_idx + 1] = c3_x[c3_idx];
        c3_idx--;
      } else {
        c3_exitg1 = true;
      }
    }

    c3_x[c3_idx + 1] = c3_xc;
  }
}

static int32_T c3_b_pivot(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_v[128], int32_T *c3_ip, int32_T c3_ia, int32_T
  c3_ib)
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_vk;
  real_T c3_vref;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_reps;
  boolean_T c3_overflow;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_vref = c3_v[*c3_ip - 1];
  c3_v[*c3_ip - 1] = c3_v[c3_ib - 1];
  c3_v[c3_ib - 1] = c3_vref;
  *c3_ip = c3_ia;
  c3_reps = 0;
  c3_i = c3_ib - 1;
  c3_st.site = &c3_x_emlrtRSI;
  c3_a = c3_ia;
  c3_b = c3_i;
  c3_b_a = c3_a;
  c3_b_b = c3_b;
  if (c3_b_a > c3_b_b) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_b_st.site = &c3_y_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
  }

  for (c3_k = c3_ia; c3_k <= c3_i; c3_k++) {
    c3_vk = c3_v[c3_k - 1];
    if (c3_vk == c3_vref) {
      c3_v[c3_k - 1] = c3_v[*c3_ip - 1];
      c3_v[*c3_ip - 1] = c3_vk;
      c3_reps++;
      (*c3_ip)++;
    } else {
      c3_c_a = c3_vk;
      c3_c_b = c3_vref;
      c3_d_a = c3_c_a;
      c3_d_b = c3_c_b;
      c3_p = (c3_d_a < c3_d_b);
      if (c3_p) {
        c3_v[c3_k - 1] = c3_v[*c3_ip - 1];
        c3_v[*c3_ip - 1] = c3_vk;
        (*c3_ip)++;
      }
    }
  }

  c3_v[c3_ib - 1] = c3_v[*c3_ip - 1];
  c3_v[*c3_ip - 1] = c3_vref;
  return c3_reps;
}

static void c3_b_medmed(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
  [128], int32_T c3_nv, int32_T c3_ia)
{
  real_T c3_tmp;
  int32_T c3_a;
  int32_T c3_b_k;
  int32_T c3_destidx;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_im;
  int32_T c3_k;
  int32_T c3_ngroupsof5;
  int32_T c3_nlast;
  while (c3_nv > 1) {
    c3_a = c3_nv;
    c3_ngroupsof5 = c3_div_nzp_s32(chartInstance, c3_a, 5, 0, 0U, 0, 0);
    c3_nlast = c3_nv - c3_ngroupsof5 * 5;
    c3_nv = c3_ngroupsof5;
    c3_i = (uint8_T)c3_ngroupsof5;
    for (c3_k = 0; c3_k < c3_i; c3_k++) {
      c3_b_k = c3_k;
      c3_i1 = c3_ia + c3_b_k * 5;
      c3_i2 = c3_i1;
      c3_im = c3_thirdOfFive(chartInstance, c3_v, c3_i1, c3_i2 + 4) - 1;
      c3_destidx = (c3_ia + c3_b_k) - 1;
      c3_tmp = c3_v[c3_destidx];
      c3_v[c3_destidx] = c3_v[c3_im];
      c3_v[c3_im] = c3_tmp;
    }

    if (c3_nlast > 0) {
      c3_i1 = c3_ia + c3_ngroupsof5 * 5;
      c3_i2 = c3_i1 + c3_nlast;
      c3_im = c3_thirdOfFive(chartInstance, c3_v, c3_i1, c3_i2 - 1) - 1;
      c3_destidx = (c3_ia + c3_ngroupsof5) - 1;
      c3_tmp = c3_v[c3_destidx];
      c3_v[c3_destidx] = c3_v[c3_im];
      c3_v[c3_im] = c3_tmp;
      c3_nv = c3_ngroupsof5 + 1;
    }
  }
}

static void c3_b_med3(SFc3_untitledInstanceStruct *chartInstance, real_T c3_v
                      [128], int32_T c3_nv, int32_T c3_ia, int32_T c3_ib)
{
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_k_a;
  real_T c3_tmp;
  real_T c3_v1;
  real_T c3_v2;
  real_T c3_v3;
  int32_T c3_a;
  int32_T c3_c;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_ic;
  int32_T c3_jc;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_p;
  if (c3_nv >= 3) {
    c3_a = c3_nv;
    c3_c = c3_div_nzp_s32(chartInstance, c3_a - 1, 2, 0, 0U, 0, 0);
    c3_ic = c3_ia + c3_c;
    c3_i1 = c3_ia;
    c3_v1 = c3_v[c3_ia - 1];
    c3_i2 = c3_ic;
    c3_v2 = c3_v[c3_ic - 1];
    c3_i3 = c3_ib;
    c3_v3 = c3_v[c3_ib - 1];
    c3_b_a = c3_v1;
    c3_b = c3_v2;
    c3_c_a = c3_b_a;
    c3_b_b = c3_b;
    c3_p = (c3_c_a < c3_b_b);
    if (c3_p) {
      c3_e_a = c3_v2;
      c3_d_b = c3_v3;
      c3_g_a = c3_e_a;
      c3_f_b = c3_d_b;
      c3_c_p = (c3_g_a < c3_f_b);
      if (c3_c_p) {
        c3_jc = c3_i2;
      } else {
        c3_i_a = c3_v1;
        c3_h_b = c3_v3;
        c3_k_a = c3_i_a;
        c3_j_b = c3_h_b;
        c3_e_p = (c3_k_a < c3_j_b);
        if (c3_e_p) {
          c3_jc = c3_i3;
        } else {
          c3_jc = c3_i1;
        }
      }
    } else {
      c3_d_a = c3_v1;
      c3_c_b = c3_v3;
      c3_f_a = c3_d_a;
      c3_e_b = c3_c_b;
      c3_b_p = (c3_f_a < c3_e_b);
      if (c3_b_p) {
        c3_jc = c3_i1;
      } else {
        c3_h_a = c3_v2;
        c3_g_b = c3_v3;
        c3_j_a = c3_h_a;
        c3_i_b = c3_g_b;
        c3_d_p = (c3_j_a < c3_i_b);
        if (c3_d_p) {
          c3_jc = c3_i3;
        } else {
          c3_jc = c3_i2;
        }
      }
    }

    if (c3_jc > c3_ia) {
      c3_tmp = c3_v[c3_ia - 1];
      c3_v[c3_ia - 1] = c3_v[c3_jc - 1];
      c3_v[c3_jc - 1] = c3_tmp;
    }
  }
}

static void c3_d_introsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_xend)
{
  static char_T c3_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c3_cv2[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c3_cv3[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c3_cv1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'o', 'p', 'E', 'm', 'p',
    't', 'y' };

  c3_coder_internal_stack c3_b_st;
  c3_sBaHy6MF1FZJsDHxMqvBaiH c3_b_x;
  c3_sBaHy6MF1FZJsDHxMqvBaiH c3_c_x;
  c3_sBaHy6MF1FZJsDHxMqvBaiH c3_frame;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  real_T c3_d;
  real_T c3_d1;
  int32_T c3_iv[2];
  int32_T c3_MAXDEPTH;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_n;
  int32_T c3_b_nd;
  int32_T c3_b_p;
  int32_T c3_b_xend;
  int32_T c3_b_xstart;
  int32_T c3_c;
  int32_T c3_c_n;
  int32_T c3_c_nd;
  int32_T c3_c_pivot;
  int32_T c3_d_n;
  int32_T c3_depth;
  int32_T c3_e_n;
  int32_T c3_exitg2;
  int32_T c3_exitg3;
  int32_T c3_i;
  int32_T c3_j;
  int32_T c3_n;
  int32_T c3_nd;
  int32_T c3_p;
  int32_T c3_pmax;
  int32_T c3_pmin;
  int32_T c3_pow2p;
  int32_T c3_t;
  int32_T c3_x;
  int32_T c3_xmid;
  int32_T c3_xstart;
  int32_T c3_y;
  boolean_T c3_exitg1;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  if (c3_xend <= 1) {
  } else if (c3_xend <= 32) {
    c3_e_insertionsort(chartInstance, c3_x_data, c3_xend);
  } else {
    c3_n = c3_xend;
    c3_x = c3_n;
    c3_p = c3_x;
    c3_b_n = c3_p;
    c3_c_n = c3_b_n;
    c3_pmax = 31;
    c3_pmin = 0;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_pmax - c3_pmin > 1)) {
      c3_p = (c3_pmin + c3_pmax) >> 1;
      c3_pow2p = 1 << c3_p;
      if (c3_pow2p == c3_c_n) {
        c3_pmax = c3_p;
        c3_exitg1 = true;
      } else if (c3_pow2p > c3_c_n) {
        c3_pmax = c3_p;
      } else {
        c3_pmin = c3_p;
      }
    }

    c3_p = c3_pmax - 1;
    c3_b = c3_p;
    c3_MAXDEPTH = c3_b << 1;
    c3_frame.xstart = 1;
    c3_frame.xend = c3_xend;
    c3_frame.depth = 0;
    c3_b_b = c3_MAXDEPTH;
    c3_y = c3_b_b << 1;
    c3_st.site = &c3_ub_emlrtRSI;
    c3_d_n = c3_y;
    c3_d = (real_T)c3_d_n;
    if (!(c3_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c3_d, &c3_f_emlrtDCI, &c3_st);
    }

    c3_iv[0] = (int32_T)muDoubleScalarFloor(c3_d);
    c3_d1 = 1.0;
    if (!(c3_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c3_d1, &c3_f_emlrtDCI, &c3_st);
    }

    c3_b_st.d.size[0] = c3_iv[0];
    c3_st.site = &c3_pb_emlrtRSI;
    c3_nd = c3_b_st.d.size[0];
    if (c3_nd <= 0) {
      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      c3_c_y = NULL;
      sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      sf_mex_call(&c3_st, &c3_j_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                  sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c3_st, NULL, "message", 1U, 1U, 14, c3_c_y)));
    }

    c3_b_st.d.data[0] = c3_frame;
    c3_b_st.n = 1;
    do {
      c3_exitg2 = 0;
      c3_e_n = c3_b_st.n;
      if (c3_e_n > 0) {
        c3_st.site = &c3_qb_emlrtRSI;
        if (c3_b_st.n <= 0) {
          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          c3_e_y = NULL;
          sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          sf_mex_call(&c3_st, &c3_k_emlrtMCI, "error", 0U, 2U, 14, c3_d_y, 14,
                      sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c3_st, NULL, "message", 1U, 1U, 14, c3_e_y)));
        }

        c3_frame = c3_b_st.d.data[c3_b_st.n - 1];
        c3_b_st.n--;
        c3_xstart = c3_frame.xstart;
        c3_xend = c3_frame.xend;
        c3_depth = c3_frame.depth + 1;
        if ((c3_xend - c3_xstart) + 1 <= 32) {
          c3_st.site = &c3_rb_emlrtRSI;
          c3_f_insertionsort(chartInstance, &c3_st, c3_x_data, c3_xstart,
                             c3_xend);
        } else if (c3_depth - 1 == c3_MAXDEPTH) {
          c3_b_heapsort(chartInstance, c3_x_data, c3_xstart, c3_xend);
        } else {
          c3_b_xstart = c3_xstart - 1;
          c3_b_xend = c3_xend - 1;
          c3_a = c3_b_xend - c3_b_xstart;
          c3_c = c3_div_nzp_s32(chartInstance, c3_a, 2, 0, 0U, 0, 0);
          c3_xmid = c3_b_xstart + c3_c;
          if (c3_x_data[c3_xmid] < c3_x_data[c3_b_xstart]) {
            c3_t = c3_x_data[c3_b_xstart];
            c3_x_data[c3_b_xstart] = c3_x_data[c3_xmid];
            c3_x_data[c3_xmid] = c3_t;
          }

          if (c3_x_data[c3_b_xend] < c3_x_data[c3_b_xstart]) {
            c3_t = c3_x_data[c3_b_xstart];
            c3_x_data[c3_b_xstart] = c3_x_data[c3_b_xend];
            c3_x_data[c3_b_xend] = c3_t;
          }

          if (c3_x_data[c3_b_xend] < c3_x_data[c3_xmid]) {
            c3_t = c3_x_data[c3_xmid];
            c3_x_data[c3_xmid] = c3_x_data[c3_b_xend];
            c3_x_data[c3_b_xend] = c3_t;
          }

          c3_c_pivot = c3_x_data[c3_xmid];
          c3_x_data[c3_xmid] = c3_x_data[c3_b_xend - 1];
          c3_x_data[c3_b_xend - 1] = c3_c_pivot;
          c3_i = c3_b_xstart;
          c3_j = c3_b_xend - 1;
          do {
            c3_exitg3 = 0;
            for (c3_i++; c3_x_data[c3_i] < c3_c_pivot; c3_i++) {
            }

            for (c3_j--; c3_c_pivot < c3_x_data[c3_j]; c3_j--) {
            }

            if (c3_i + 1 >= c3_j + 1) {
              c3_exitg3 = 1;
            } else {
              c3_t = c3_x_data[c3_i];
              c3_x_data[c3_i] = c3_x_data[c3_j];
              c3_x_data[c3_j] = c3_t;
            }
          } while (c3_exitg3 == 0);

          c3_b_p = c3_i + 1;
          c3_x_data[c3_b_xend - 1] = c3_x_data[c3_i];
          c3_x_data[c3_i] = c3_c_pivot;
          if (c3_b_p + 1 < c3_xend) {
            c3_b_x.xstart = c3_b_p + 1;
            c3_b_x.xend = c3_xend;
            c3_b_x.depth = c3_depth;
            c3_st.site = &c3_sb_emlrtRSI;
            c3_b_nd = c3_b_st.d.size[0];
            if (c3_b_st.n >= c3_b_nd) {
              c3_f_y = NULL;
              sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c3_h_y = NULL;
              sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c3_st, &c3_j_emlrtMCI, "error", 0U, 2U, 14, c3_f_y,
                          14, sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c3_st, NULL, "message", 1U, 1U, 14, c3_h_y)));
            }

            c3_b_st.d.data[c3_b_st.n] = c3_b_x;
            c3_b_st.n++;
          }

          if (c3_xstart < c3_b_p) {
            c3_c_x.xstart = c3_xstart;
            c3_c_x.xend = c3_b_p;
            c3_c_x.depth = c3_depth;
            c3_st.site = &c3_tb_emlrtRSI;
            c3_c_nd = c3_b_st.d.size[0];
            if (c3_b_st.n >= c3_c_nd) {
              c3_g_y = NULL;
              sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c3_i_y = NULL;
              sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c3_st, &c3_j_emlrtMCI, "error", 0U, 2U, 14, c3_g_y,
                          14, sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c3_st, NULL, "message", 1U, 1U, 14, c3_i_y)));
            }

            c3_b_st.d.data[c3_b_st.n] = c3_c_x;
            c3_b_st.n++;
          }
        }
      } else {
        c3_exitg2 = 1;
      }
    } while (c3_exitg2 == 0);
  }
}

static void c3_e_insertionsort(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_x_data[], int32_T c3_xend)
{
  int32_T c3_idx;
  int32_T c3_k;
  int32_T c3_xc;
  (void)chartInstance;
  for (c3_k = 2; c3_k <= c3_xend; c3_k++) {
    c3_xc = c3_x_data[c3_k - 1];
    c3_idx = c3_k - 1;
    while ((c3_idx >= 1) && (c3_xc < c3_x_data[c3_idx - 1])) {
      c3_x_data[c3_idx] = c3_x_data[c3_idx - 1];
      c3_idx--;
    }

    c3_x_data[c3_idx] = c3_xc;
  }
}

static void c3_f_insertionsort(SFc3_untitledInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_x_data[], int32_T c3_xstart, int32_T c3_xend)
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_i;
  int32_T c3_idx;
  int32_T c3_k;
  int32_T c3_xc;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_i = c3_xstart + 1;
  c3_st.site = &c3_vb_emlrtRSI;
  c3_a = c3_i;
  c3_b = c3_xend;
  c3_b_a = c3_a;
  c3_b_b = c3_b;
  if (c3_b_a > c3_b_b) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_b_st.site = &c3_y_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
  }

  for (c3_k = c3_i; c3_k <= c3_xend; c3_k++) {
    c3_xc = c3_x_data[c3_k - 1];
    c3_idx = c3_k - 1;
    while ((c3_idx >= c3_xstart) && (c3_xc < c3_x_data[c3_idx - 1])) {
      c3_x_data[c3_idx] = c3_x_data[c3_idx - 1];
      c3_idx--;
    }

    c3_x_data[c3_idx] = c3_xc;
  }
}

static void c3_b_heapsort(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_xstart, int32_T c3_xend)
{
  int32_T c3_b_n;
  int32_T c3_b_xend;
  int32_T c3_b_xstart;
  int32_T c3_i;
  int32_T c3_idx;
  int32_T c3_k;
  int32_T c3_n;
  int32_T c3_t;
  c3_n = c3_xend - c3_xstart;
  c3_b_xstart = c3_xstart;
  c3_b_xend = c3_xend;
  c3_b_n = c3_n + 1;
  for (c3_idx = c3_b_n; c3_idx >= 1; c3_idx--) {
    c3_b_heapify(chartInstance, c3_x_data, c3_idx, c3_b_xstart, c3_b_xend);
  }

  c3_i = c3_n;
  for (c3_k = 0; c3_k < c3_i; c3_k++) {
    c3_t = c3_x_data[c3_xend - 1];
    c3_x_data[c3_xend - 1] = c3_x_data[c3_xstart - 1];
    c3_x_data[c3_xstart - 1] = c3_t;
    c3_xend--;
    c3_b_heapify(chartInstance, c3_x_data, 1, c3_xstart, c3_xend);
  }
}

static void c3_b_heapify(SFc3_untitledInstanceStruct *chartInstance, int32_T
  c3_x_data[], int32_T c3_idx, int32_T c3_xstart, int32_T c3_xend)
{
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_y;
  int32_T c3_cmpIdx;
  int32_T c3_extremum;
  int32_T c3_extremumIdx;
  int32_T c3_leftIdx;
  int32_T c3_rightIdx;
  int32_T c3_xcmp;
  int32_T c3_xoff;
  int32_T c3_xr;
  int32_T c3_y;
  boolean_T c3_changed;
  (void)chartInstance;
  c3_changed = true;
  c3_xoff = c3_xstart - 1;
  c3_extremumIdx = (c3_idx + c3_xoff) - 1;
  c3_b = c3_idx;
  c3_y = c3_b << 1;
  c3_leftIdx = c3_y + c3_xoff;
  while (c3_changed && (c3_leftIdx < c3_xend)) {
    c3_changed = false;
    c3_rightIdx = c3_leftIdx;
    c3_extremum = c3_x_data[c3_extremumIdx];
    c3_cmpIdx = c3_leftIdx;
    c3_xcmp = c3_x_data[c3_leftIdx - 1];
    c3_xr = c3_x_data[c3_rightIdx];
    if (c3_xcmp < c3_xr) {
      c3_cmpIdx = c3_leftIdx + 1;
      c3_xcmp = c3_xr;
    }

    if (c3_extremum < c3_xcmp) {
      c3_x_data[c3_extremumIdx] = c3_xcmp;
      c3_x_data[c3_cmpIdx - 1] = c3_extremum;
      c3_extremumIdx = c3_cmpIdx - 1;
      c3_b_b = c3_cmpIdx - c3_xoff;
      c3_b_y = c3_b_b << 1;
      c3_leftIdx = c3_b_y + c3_xoff;
      c3_changed = true;
    }
  }

  if (c3_changed && (c3_leftIdx <= c3_xend)) {
    c3_extremum = c3_x_data[c3_extremumIdx];
    c3_xcmp = c3_x_data[c3_leftIdx - 1];
    if (c3_extremum < c3_xcmp) {
      c3_x_data[c3_extremumIdx] = c3_xcmp;
      c3_x_data[c3_leftIdx - 1] = c3_extremum;
    }
  }
}

static void c3_array_real_T_SetSize(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, c3_coder_array_real_T *c3_coderArray, const
  emlrtRTEInfo *c3_srcLocation, int32_T c3_size0)
{
  real_T *c3_newData;
  int32_T c3_newCapacity;
  int32_T c3_newNumel;
  (void)chartInstance;
  c3_coderArray->size[0] = c3_size0;
  c3_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c3_coderArray->size[0], c3_srcLocation, (void *)c3_sp);
  if (c3_newNumel > c3_coderArray->vector.allocated) {
    c3_newCapacity = c3_coderArray->vector.allocated;
    if (c3_newCapacity < 16) {
      c3_newCapacity = 16;
    }

    while (c3_newCapacity < c3_newNumel) {
      if (c3_newCapacity > 1073741823) {
        c3_newCapacity = MAX_int32_T;
      } else {
        c3_newCapacity <<= 1;
      }
    }

    c3_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c3_newCapacity);
    if ((void *)c3_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c3_srcLocation, (void *)c3_sp);
    }

    if ((void *)c3_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c3_srcLocation, (void *)c3_sp);
    }

    if (c3_coderArray->vector.data != NULL) {
      memcpy(c3_newData, c3_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c3_coderArray->vector.numel);
      if (c3_coderArray->vector.owner) {
        emlrtFreeMex(c3_coderArray->vector.data);
      }
    }

    c3_coderArray->vector.data = c3_newData;
    c3_coderArray->vector.allocated = c3_newCapacity;
    c3_coderArray->vector.owner = true;
  }

  c3_coderArray->vector.numel = c3_newNumel;
}

static void c3_array_int32_T_SetSize(SFc3_untitledInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, c3_coder_array_int32_T *c3_coderArray, const
  emlrtRTEInfo *c3_srcLocation, int32_T c3_size0)
{
  int32_T c3_newCapacity;
  int32_T c3_newNumel;
  int32_T *c3_newData;
  (void)chartInstance;
  c3_coderArray->size[0] = c3_size0;
  c3_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c3_coderArray->size[0], c3_srcLocation, (void *)c3_sp);
  if (c3_newNumel > c3_coderArray->vector.allocated) {
    c3_newCapacity = c3_coderArray->vector.allocated;
    if (c3_newCapacity < 16) {
      c3_newCapacity = 16;
    }

    while (c3_newCapacity < c3_newNumel) {
      if (c3_newCapacity > 1073741823) {
        c3_newCapacity = MAX_int32_T;
      } else {
        c3_newCapacity <<= 1;
      }
    }

    c3_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c3_newCapacity);
    if ((void *)c3_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c3_srcLocation, (void *)c3_sp);
    }

    if ((void *)c3_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c3_srcLocation, (void *)c3_sp);
    }

    if (c3_coderArray->vector.data != NULL) {
      memcpy(c3_newData, c3_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c3_coderArray->vector.numel);
      if (c3_coderArray->vector.owner) {
        emlrtFreeMex(c3_coderArray->vector.data);
      }
    }

    c3_coderArray->vector.data = c3_newData;
    c3_coderArray->vector.allocated = c3_newCapacity;
    c3_coderArray->vector.owner = true;
  }

  c3_coderArray->vector.numel = c3_newNumel;
}

static void c3_array_sparse_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_sparse *c3_pStruct)
{
  c3_array_real_T_Constructor(chartInstance, &c3_pStruct->d);
  c3_array_int32_T_Constructor(chartInstance, &c3_pStruct->colidx);
  c3_array_int32_T_Constructor(chartInstance, &c3_pStruct->rowidx);
}

static void c3_array_real_T_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_real_T *c3_coderArray)
{
  (void)chartInstance;
  c3_coderArray->vector.data = (real_T *)NULL;
  c3_coderArray->vector.numel = 0;
  c3_coderArray->vector.allocated = 0;
  c3_coderArray->vector.owner = true;
  c3_coderArray->size[0] = 0;
}

static void c3_array_int32_T_Constructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_int32_T *c3_coderArray)
{
  (void)chartInstance;
  c3_coderArray->vector.data = (int32_T *)NULL;
  c3_coderArray->vector.numel = 0;
  c3_coderArray->vector.allocated = 0;
  c3_coderArray->vector.owner = true;
  c3_coderArray->size[0] = 0;
}

static void c3_array_real_T_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_real_T *c3_coderArray)
{
  (void)chartInstance;
  if (c3_coderArray->vector.owner && (c3_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c3_coderArray->vector.data);
  }
}

static void c3_array_sparse_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_sparse *c3_pStruct)
{
  c3_array_real_T_Destructor(chartInstance, &c3_pStruct->d);
  c3_array_int32_T_Destructor(chartInstance, &c3_pStruct->colidx);
  c3_array_int32_T_Destructor(chartInstance, &c3_pStruct->rowidx);
}

static void c3_array_int32_T_Destructor(SFc3_untitledInstanceStruct
  *chartInstance, c3_coder_array_int32_T *c3_coderArray)
{
  (void)chartInstance;
  if (c3_coderArray->vector.owner && (c3_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c3_coderArray->vector.data);
  }
}

static int32_T c3_div_nzp_s32(SFc3_untitledInstanceStruct *chartInstance,
  int32_T c3_numerator, int32_T c3_denominator, int32_T c3_EMLOvCount_src_loc,
  uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc)
{
  int32_T c3_quotient;
  uint32_T c3_absDenominator;
  uint32_T c3_absNumerator;
  uint32_T c3_tempAbsQuotient;
  boolean_T c3_quotientNeedsNegation;
  (void)chartInstance;
  (void)c3_EMLOvCount_src_loc;
  (void)c3_ssid_src_loc;
  (void)c3_offset_src_loc;
  (void)c3_length_src_loc;
  if (c3_numerator < 0) {
    c3_absNumerator = ~(uint32_T)c3_numerator + 1U;
  } else {
    c3_absNumerator = (uint32_T)c3_numerator;
  }

  if (c3_denominator < 0) {
    c3_absDenominator = ~(uint32_T)c3_denominator + 1U;
  } else {
    c3_absDenominator = (uint32_T)c3_denominator;
  }

  c3_quotientNeedsNegation = ((c3_numerator < 0) != (c3_denominator < 0));
  c3_tempAbsQuotient = c3_absNumerator / c3_absDenominator;
  if (c3_quotientNeedsNegation) {
    c3_quotient = -(int32_T)c3_tempAbsQuotient;
  } else {
    c3_quotient = (int32_T)c3_tempAbsQuotient;
  }

  return c3_quotient;
}

static void init_dsm_address_info(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_untitledInstanceStruct *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_a3_in = (real_T (*)[128])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_a3_smoothed = (real_T (*)[128])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2819391761U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1061499395U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4118289508U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1649774113U);
}

mxArray *sf_c3_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.CXSparseAPI"));
  return(mxcell3p);
}

mxArray *sf_c3_untitled_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("makeCXSparseMatrix");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_untitled_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOl3QNLPgkU/N5J+ASg/0Ti+ODc/vyQjNYUBFk4gAA"
    "BVORDF"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "speT45VBbCExN9y26CVluYC";
}

static void sf_opaque_initialize_c3_untitled(void *chartInstanceVar)
{
  initialize_params_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
  initialize_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_untitled(void *chartInstanceVar)
{
  enable_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_untitled(void *chartInstanceVar)
{
  disable_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_untitled(void *chartInstanceVar)
{
  sf_gateway_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_untitled(SimStruct* S)
{
  return get_sim_state_c3_untitled((SFc3_untitledInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_untitled(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_untitled((SFc3_untitledInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_untitled(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_untitled((SFc3_untitledInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_untitled(void *chartInstanceVar)
{
  mdl_start_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc3_untitledInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c3_untitled(void *chartInstanceVar)
{
  mdl_terminate_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_untitled(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_untitled((SFc3_untitledInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_untitled_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWE2P20QYnmyXVctHaSWkckACiQsnVLGAQCDoruOUiN1uhLOL4FJN7DfxaMcz7nxkE879HZX",
    "4Cz33zl+okDjwDzhy5B3HyZpsyHocqdtiyesd28887zzzfjmk1T0keNzE87s7hOzg9TqeW2R2vF",
    "aOW5Vzdn+bfF2Oe68TEqdUma4YSuJ/xDKBEYjIDods4okVNutRRTPdgFfQDH4ALbk1TAo/45kYg",
    "gIR4wS5VMaLV7PMciZOO1bEjln/mLI4jVJpebKPE9LkSPDpf/Hm1vSQsc0UxKYDkJhUSTtKO5yO",
    "1qugzFmQQnyqbeatlQYT2dwtVR9abljOIZxA3BXaUFRBX7LeyFADgZl4ewjT0Rwts5wzKuprnVI",
    "dQY7eYeA4T/DvkTWoXk1e5BswQY1UjPIw44Hz8JrYHkc7D9GtubfOJjNtGNjRiImRU1fZDASuH/",
    "2khlbDQI5B0REcCc8YdKsLJ8UGL/yyfgx2nVs2ikGbzXZFN8IWvOEYFdINeTuxCCjn2g/bl/kBj",
    "IEX/G1qaAPsjN8DrDVL+vKEKhcFnpFkBXtkocQGUiSs/g6Pl1BFwn2AybMGnGXOpSBBmRemLya6",
    "zCetNjILMIzaBwc1+S5iu8KAGtIYauc+RZkGNLjwK0/ehGk64A6NKplilbVnANEYSvTQivaZVKe",
    "osW+SPdfKRYIfGpIRtMFAkTBC9O4Tym1NmzONGc65x7HGjOXHi1gXP43AMY1TSFw9YRwOQbsJdO",
    "38jHVkD1c7ZmbaBh0rlteNJKshwULiVOpPczgWp0KeiY6SWVR2BGv8CgCzBlUCy8I+liU17aDx9",
    "axW8KjvPKtJe5ZRw+nA+cZ9EFhZ3FpdJaQxRlUosHVDgzbBRuwXLO1CM22wnZqGRQwkRT/6bsuv",
    "H71djncXsdTVfYU7RbEMC+yU9gZFswd9lkFxI6LYU8yG5eF475Jz3htb63m38L9WQxzZEHevgtt",
    "eoc8bFdytchzvPrQCk4vTeBX/mzV0roMjF3Dn+s6vH1XwrRW8pHLdZF+qOr21xLO9hNsptXo7fN",
    "L5/cM/nz77+I9ff2NfPd6E/7mnH98sx+/N+7JF5RpfSO7Fd9slfnBnyQ/cWOfQ//Szk/1BEE4ef",
    "Dn95PPghNufgtm+eNo7v/8BngYTW5EnVdxNym8sN6Z21vu7+b+o2Ltzyfw3Kv5EyF/fboZ/517T",
    "uKG7D3UmpUkrcfOq5Iuryk9XaWedPNZ6wTjygnGbrs83P7/q799dkxfI0vu3XuJ1rMtPPnX6ZVv",
    "Xc+JXl94vx98svp2DlPFkRfdePsYGe7jq6f/Ev//21G/eN4ROv/LHv5939wTlU2zXZ59D5e2ecr",
    "87LR4poHr1N9FV1KE68e3evvav+L5G7u9/37iO/QPG5/yU",
    ""
  };

  static char newstr [1397] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_untitled(SimStruct *S)
{
  const char* newstr = sf_c3_untitled_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1184777487U));
  ssSetChecksum1(S,(3001099226U));
  ssSetChecksum2(S,(2715627196U));
  ssSetChecksum3(S,(2218486215U));
}

static void mdlRTW_c3_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_untitled(SimStruct *S)
{
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)utMalloc(sizeof
    (SFc3_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_untitledInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_untitled;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_untitled;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c3_untitled;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_untitled;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_untitled(chartInstance);
}

void c3_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
