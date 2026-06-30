/* Include files */

#include "untitled_sfun.h"
#include "c4_untitled.h"
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
static emlrtMCInfo c4_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 242,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 245,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 409,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 420,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI = { 447,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI = { 398,/* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI = { 419,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI = { 62,/* lineNo */
  39,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI = { 82,/* lineNo */
  13,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c4_l_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 13, /* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#untitled:48"                       /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 17,/* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#untitled:48"                       /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 16,/* lineNo */
  "MATLAB Function3",                  /* fcnName */
  "#untitled:48"                       /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 123,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 150,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 505,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 579,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 174,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 261,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 13,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 1450,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 160,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 316,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 312,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 291,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 459,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 357,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 139,/* lineNo */
  "median",                            /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\median.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 108,/* lineNo */
  "vmedian",                           /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vmedian.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 113,/* lineNo */
  "vmedian",                           /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vmedian.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 94,/* lineNo */
  "quickselect",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\quickselect.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 177,/* lineNo */
  "quickselect",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\quickselect.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 134,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 166,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 167,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 178,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 182,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 189,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 195,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 566,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 23,/* lineNo */
  "union",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\union.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 97,/* lineNo */
  "eml_setop",                         /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 579,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 641,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 82,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 140,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 42,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 44,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 47,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 55,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 58,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 41,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 18,/* lineNo */
  "insertionsort",                     /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sparse",                            /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 439,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 440,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 441,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 526,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 527,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 548,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 562,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 167,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 178,/* lineNo */
  47,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 584,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_l_emlrtRTEI = { 585,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 593,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_n_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 598,/* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 598,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 600,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 579,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 182,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 191,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 187,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 189,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 195,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 679,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 680,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 223,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 224,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 225,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 415,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 426,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI = { 451,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "introsort",                         /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "insertionsort",                     /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pName */
};

static emlrtRTEInfo c4_lb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI = { 40,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c4_nb_emlrtRTEI = { 48,/* lineNo */
  45,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI = { 261,/* lineNo */
  19,                                  /* colNo */
  "filtfilt",                          /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { 1,  /* iFirst */
  128,                                 /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI = { 52, /* lineNo */
  27,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  41,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI = { 41,/* lineNo */
  27,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c4_pb_emlrtRTEI = { 34,/* lineNo */
  19,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48"                       /* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI = { 29,/* lineNo */
  13,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48"                       /* pName */
};

static emlrtBCInfo c4_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  23,                                  /* colNo */
  "peak_locs",                         /* aName */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 30,/* lineNo */
  23,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  52,                                  /* lineNo */
  44,                                  /* colNo */
  "alpha",                             /* aName */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 52,/* lineNo */
  44,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  52,                                  /* lineNo */
  64,                                  /* colNo */
  "sigmoid_trans",                     /* aName */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI = { 52,/* lineNo */
  64,                                  /* colNo */
  "MATLAB Function3",                  /* fName */
  "#untitled:48",                      /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c4_rb_emlrtRTEI = { 618,/* lineNo */
  18,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtBCInfo c4_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  528,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  527,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  475,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  526,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  502,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  523,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  511,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  497,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  489,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  553,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  555,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  555,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  558,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  598,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  603,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  628,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  623,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  85,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_f_emlrtDCI = { 48,/* lineNo */
  63,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m",/* pName */
  4                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void initialize_params_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance);
static void mdl_start_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void mdl_terminate_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_untitled(SFc4_untitledInstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c4_untitled
  (SFc4_untitledInstanceStruct *chartInstance);
static void enable_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void disable_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void sf_gateway_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void ext_mode_exec_c4_untitled(SFc4_untitledInstanceStruct *chartInstance);
static void c4_update_jit_animation_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance);
static void c4_do_animation_call_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c4_untitled(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void c4_filtfilt(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_varargin_2[128], real_T c4_y[128]);
static void c4_introsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp, int32_T c4_b_x[4]);
static void c4_insertionsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp, int32_T c4_b_x[4]);
static void c4_check_forloop_overflow_error(SFc4_untitledInstanceStruct
  *chartInstance, const emlrtStack *c4_sp);
static void c4_warning(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp);
static void c4_filter(SFc4_untitledInstanceStruct *chartInstance, real_T c4_b[3],
                      real_T c4_x[140], real_T c4_zi[2], real_T c4_y[140]);
static void c4_pivot(SFc4_untitledInstanceStruct *chartInstance, const
                     emlrtStack *c4_sp, real_T c4_v[128], int32_T c4_ip, int32_T
                     c4_ia, int32_T c4_ib, real_T c4_b_v[128], int32_T *c4_b_ip,
                     int32_T *c4_reps);
static void c4_medmed(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
                      [128], int32_T c4_nv, int32_T c4_ia, real_T c4_b_v[128]);
static int32_T c4_thirdOfFive(SFc4_untitledInstanceStruct *chartInstance, real_T
  c4_v[128], int32_T c4_ia, int32_T c4_ib);
static void c4_med3(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v[128],
                    int32_T c4_nv, int32_T c4_ia, int32_T c4_ib, real_T c4_b_v
                    [128]);
static void c4_findpeaks(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[128], real_T c4_varargin_2, real_T
  c4_Ypk_data[], int32_T c4_Ypk_size[1], real_T c4_Xpk_data[], int32_T
  c4_Xpk_size[1]);
static void c4_do_vectors(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_a_data[], int32_T c4_a_size[1], int32_T
  c4_b_data[], int32_T c4_b_size[1], int32_T c4_c_data[], int32_T c4_c_size[1],
  int32_T c4_ia_data[], int32_T c4_ia_size[1], int32_T c4_ib_data[], int32_T
  c4_ib_size[1]);
static boolean_T c4_issorted(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1]);
static void c4_b_introsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1], int32_T c4_xend,
  int32_T c4_b_x_data[], int32_T c4_b_x_size[1]);
static void c4_b_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x_data[], int32_T c4_x_size[1], int32_T c4_xend, int32_T
  c4_b_x_data[], int32_T c4_b_x_size[1]);
static void c4_c_insertionsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1], int32_T
  c4_xstart, int32_T c4_xend, int32_T c4_b_x_data[], int32_T c4_b_x_size[1]);
static void c4_heapsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1], int32_T c4_xstart, int32_T c4_xend, int32_T
  c4_b_x_data[], int32_T c4_b_x_size[1]);
static void c4_heapify(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1], int32_T c4_idx, int32_T c4_xstart, int32_T
  c4_xend, int32_T c4_b_x_data[], int32_T c4_b_x_size[1]);
static void c4_indexShapeCheck(SFc4_untitledInstanceStruct *chartInstance);
static void c4_b_indexShapeCheck(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2]);
static void c4_emlrt_marshallIn(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier, real_T c4_y[128]);
static void c4_b_emlrt_marshallIn(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[128]);
static void c4_slStringInitializeDynamicBuffers(SFc4_untitledInstanceStruct
  *chartInstance);
static const mxArray *c4_feval(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_b_feval(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_c_introsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp);
static void c4_d_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x[4], c4_anonymous_function c4_cmp);
static int32_T c4_b_pivot(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_v[128], int32_T *c4_ip, int32_T c4_ia, int32_T
  c4_ib);
static void c4_b_medmed(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
  [128], int32_T c4_nv, int32_T c4_ia);
static void c4_b_med3(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
                      [128], int32_T c4_nv, int32_T c4_ia, int32_T c4_ib);
static void c4_d_introsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_xend);
static void c4_e_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x_data[], int32_T c4_xend);
static void c4_f_insertionsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_xstart, int32_T c4_xend);
static void c4_b_heapsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_xstart, int32_T c4_xend);
static void c4_b_heapify(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_idx, int32_T c4_xstart, int32_T c4_xend);
static void c4_array_real_T_SetSize(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray, const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_int32_T_SetSize(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray, const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_sparse_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_sparse *c4_pStruct);
static void c4_array_real_T_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_array_int32_T_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray);
static void c4_array_real_T_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_array_sparse_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_sparse *c4_pStruct);
static void c4_array_int32_T_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray);
static int32_T c4_div_nzp_s32(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_numerator, int32_T c4_denominator, int32_T c4_EMLOvCount_src_loc,
  uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_untitledInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c4_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "signal_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_untitled(SFc4_untitledInstanceStruct *
  chartInstance)
{
  static const int32_T c4_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c4_condTxtEndIdx[2] = { 1142, 1156 };

  static const int32_T c4_condTxtStartIdx[2] = { 1134, 1146 };

  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c4_JITStateAnimation[0],
                        &chartInstance->c4_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    10U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 5U, 0U,
                  0U, 0U, 2U, 0U, 2U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, "c4_untitled",
                     0, -1, 2012);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 260, 287, -1,
                    323, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1131, 1156, -1,
                    1915, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 1289, 1316,
                    1402, 1880, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 3U, 1402, 1447, -1,
                    1880, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 1561, 1572,
                    1668, 1771, false);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 887, 914, 1935);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1047, 1118,
                     1927);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1134, 1156,
                      2U, 0U, &c4_condTxtStartIdx[0], &c4_condTxtEndIdx[0], 3U,
                      &c4_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 263,
    287, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1134,
    1142, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 1146,
    1156, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 3U, 1292,
    1316, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 1409,
    1447, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 5U, 1564,
    1572, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c4_untitled
  (SFc4_untitledInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  static real_T c4_dv[5] = { 4.5397868702434395E-5, 0.0066928509242848554, 0.5,
    0.99330714907571527, 0.99995460213129761 };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_a3_smoothed_full[128];
  real_T c4_a__1_data[128];
  real_T c4_alpha[128];
  real_T c4_b_a3_in[128];
  real_T c4_c_y[128];
  real_T c4_peak_locs_data[128];
  real_T c4_b_b;
  real_T c4_b_idx;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_i;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_d_c;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_dist;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_h_a;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_j_x;
  real_T c4_j_y;
  real_T c4_k_x;
  real_T c4_k_y;
  real_T c4_l_x;
  real_T c4_l_y;
  real_T c4_m;
  real_T c4_m1;
  real_T c4_m_x;
  real_T c4_m_y;
  real_T c4_minval;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_rel_idx;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_u_x;
  real_T c4_varargin_1;
  real_T c4_varargin_2;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_a__1_size[1];
  int32_T c4_peak_locs_size[1];
  int32_T c4_a;
  int32_T c4_b_a;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_ia;
  int32_T c4_b_ib;
  int32_T c4_b_ifirst;
  int32_T c4_b_ilast;
  int32_T c4_b_ipiv;
  int32_T c4_b_k;
  int32_T c4_b_nv;
  int32_T c4_b_oldnv;
  int32_T c4_b_reps;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_c;
  int32_T c4_c_ifirst;
  int32_T c4_c_ilast;
  int32_T c4_c_k;
  int32_T c4_d_ilast;
  int32_T c4_d_k;
  int32_T c4_e_a;
  int32_T c4_e_c;
  int32_T c4_e_ilast;
  int32_T c4_e_k;
  int32_T c4_exitg1;
  int32_T c4_f_a;
  int32_T c4_f_c;
  int32_T c4_f_k;
  int32_T c4_g_a;
  int32_T c4_g_c;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_ia;
  int32_T c4_ib;
  int32_T c4_idx;
  int32_T c4_ifirst;
  int32_T c4_ilast;
  int32_T c4_ipiv;
  int32_T c4_k;
  int32_T c4_nv;
  int32_T c4_oldnv;
  int32_T c4_reps;
  int32_T c4_vlen;
  boolean_T c4_b;
  boolean_T c4_b_checkspeed;
  boolean_T c4_b_isslow;
  boolean_T c4_c_b;
  boolean_T c4_checkspeed;
  boolean_T c4_exitg2;
  boolean_T c4_guard1;
  boolean_T c4_isslow;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  for (c4_i = 0; c4_i < 128; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U,
                      (*chartInstance->c4_a3_in)[c4_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  for (c4_i1 = 0; c4_i1 < 128; c4_i1++) {
    c4_b_a3_in[c4_i1] = (*chartInstance->c4_a3_in)[c4_i1];
  }

  covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                 covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance, 4U,
    0U, 0U, 1.0, 0.0, -1, 0U, 0));
  c4_b_st.site = &c4_emlrtRSI;
  c4_filtfilt(chartInstance, &c4_b_st, c4_b_a3_in, c4_a3_smoothed_full);
  for (c4_k = 0; c4_k < 128; c4_k++) {
    c4_c_k = c4_k;
    c4_x = c4_b_a3_in[c4_c_k];
    c4_y = muDoubleScalarAbs(c4_x);
    c4_alpha[c4_c_k] = c4_y;
  }

  for (c4_b_k = 0; c4_b_k < 128; c4_b_k++) {
    c4_d_k = c4_b_k;
    c4_b_x = c4_b_a3_in[c4_d_k];
    c4_b_y = muDoubleScalarAbs(c4_b_x);
    c4_c_y[c4_d_k] = c4_b_y;
  }

  c4_b_st.site = &c4_b_emlrtRSI;
  c4_c_st.site = &c4_t_emlrtRSI;
  c4_e_k = 1;
  do {
    c4_exitg1 = 0;
    if (c4_e_k - 1 < 128) {
      c4_f_k = c4_e_k - 1;
      c4_c_x = c4_c_y[c4_f_k];
      c4_b = muDoubleScalarIsNaN(c4_c_x);
      if (c4_b) {
        c4_d = rtNaN;
        c4_exitg1 = 1;
      } else {
        c4_e_k++;
      }
    } else {
      c4_d_st.site = &c4_u_emlrtRSI;
      c4_ipiv = 65;
      c4_ia = 1;
      c4_ib = 128;
      c4_ifirst = 1;
      c4_ilast = 127;
      c4_oldnv = 128;
      c4_checkspeed = false;
      c4_isslow = false;
      c4_exitg2 = false;
      while ((!c4_exitg2) && (c4_ia < c4_ib)) {
        c4_b_ilast = c4_ipiv;
        c4_e_st.site = &c4_w_emlrtRSI;
        c4_reps = c4_b_pivot(chartInstance, &c4_e_st, c4_c_y, &c4_b_ilast, c4_ia,
                             c4_ib);
        c4_ilast = c4_b_ilast - 1;
        c4_guard1 = false;
        if (c4_b_ilast >= 65) {
          c4_ifirst = c4_b_ilast - c4_reps;
          if (c4_ifirst <= 65) {
            c4_exitg2 = true;
          } else {
            c4_ib = c4_b_ilast - 1;
            c4_guard1 = true;
          }
        } else {
          c4_ia = c4_b_ilast + 1;
          c4_guard1 = true;
        }

        if (c4_guard1) {
          c4_c_a = c4_ib - c4_ia;
          c4_c_c = c4_c_a + 1;
          c4_nv = c4_c_c;
          if (c4_checkspeed) {
            c4_e_a = c4_oldnv;
            c4_e_c = c4_div_nzp_s32(chartInstance, c4_e_a, 2, 0, 1U, 545, 18);
            c4_isslow = (c4_nv > c4_e_c);
            c4_oldnv = c4_nv;
          }

          c4_checkspeed = !c4_checkspeed;
          if (c4_isslow) {
            c4_b_medmed(chartInstance, c4_c_y, c4_nv, c4_ia);
          } else {
            c4_b_med3(chartInstance, c4_c_y, c4_nv, c4_ia, c4_ib);
          }

          c4_ipiv = c4_ia;
          c4_ifirst = c4_ia;
          c4_ilast = c4_ib - 1;
        }
      }

      c4_m = c4_c_y[c4_ilast];
      c4_a = c4_ifirst;
      c4_c = c4_a;
      c4_b_ifirst = c4_c;
      c4_b_a = c4_ilast;
      c4_b_c = c4_b_a + 1;
      c4_c_ilast = c4_b_c - 1;
      c4_d = c4_m;
      if (c4_b_ifirst > 64) {
        c4_d_st.site = &c4_v_emlrtRSI;
        c4_vlen = c4_c_ilast;
        if (c4_vlen < 64) {
          c4_m1 = rtNaN;
        } else {
          c4_b_ipiv = 64;
          c4_b_ia = 1;
          c4_b_ib = c4_vlen;
          c4_d_ilast = c4_vlen;
          c4_b_oldnv = c4_vlen;
          c4_b_checkspeed = false;
          c4_b_isslow = false;
          c4_exitg2 = false;
          while ((!c4_exitg2) && (c4_b_ia < c4_b_ib)) {
            c4_e_ilast = c4_b_ipiv;
            c4_e_st.site = &c4_w_emlrtRSI;
            c4_b_reps = c4_b_pivot(chartInstance, &c4_e_st, c4_c_y, &c4_e_ilast,
              c4_b_ia, c4_b_ib);
            c4_d_ilast = c4_e_ilast;
            c4_guard1 = false;
            if (c4_e_ilast >= 64) {
              c4_c_ifirst = c4_e_ilast - c4_b_reps;
              if (c4_c_ifirst <= 64) {
                c4_exitg2 = true;
              } else {
                c4_b_ib = c4_e_ilast - 1;
                c4_guard1 = true;
              }
            } else {
              c4_b_ia = c4_e_ilast + 1;
              c4_guard1 = true;
            }

            if (c4_guard1) {
              c4_f_a = c4_b_ib - c4_b_ia;
              c4_f_c = c4_f_a + 1;
              c4_b_nv = c4_f_c;
              if (c4_b_checkspeed) {
                c4_g_a = c4_b_oldnv;
                c4_g_c = c4_div_nzp_s32(chartInstance, c4_g_a, 2, 0, 1U, 545, 18);
                c4_b_isslow = (c4_b_nv > c4_g_c);
                c4_b_oldnv = c4_b_nv;
              }

              c4_b_checkspeed = !c4_b_checkspeed;
              if (c4_b_isslow) {
                c4_b_medmed(chartInstance, c4_c_y, c4_b_nv, c4_b_ia);
              } else {
                c4_b_med3(chartInstance, c4_c_y, c4_b_nv, c4_b_ia, c4_b_ib);
              }

              c4_b_ipiv = c4_b_ia;
              c4_d_ilast = c4_b_ib;
            }
          }

          c4_m1 = c4_c_y[c4_d_ilast - 1];
        }

        c4_d_a = c4_m;
        c4_b_b = c4_m1;
        c4_d_x = c4_d_a;
        c4_c_b = muDoubleScalarIsInf(c4_d_x);
        if (c4_c_b) {
          c4_d4 = (c4_d_a + c4_b_b) / 2.0;
        } else {
          c4_d4 = c4_d_a + (c4_b_b - c4_d_a) / 2.0;
        }

        c4_d = c4_d4;
      }

      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  c4_d_y = c4_d;
  c4_b_st.site = &c4_c_emlrtRSI;
  c4_findpeaks(chartInstance, &c4_b_st, c4_alpha, 0.6 * c4_d_y, c4_a__1_data,
               c4_a__1_size, c4_peak_locs_data, c4_peak_locs_size);
  for (c4_i2 = 0; c4_i2 < 128; c4_i2++) {
    c4_alpha[c4_i2] = 1.0;
  }

  c4_d1 = (real_T)c4_peak_locs_size[0];
  c4_i3 = (int32_T)c4_d1;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_d1, mxDOUBLE_CLASS, c4_i3,
    &c4_qb_emlrtRTEI, &c4_st);
  for (c4_b_i = 0; c4_b_i < c4_i3; c4_b_i++) {
    c4_c_i = 1.0 + (real_T)c4_b_i;
    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 1);
    if (c4_c_i != (real_T)(int32_T)muDoubleScalarFloor(c4_c_i)) {
      emlrtIntegerCheckR2012b(c4_c_i, &c4_c_emlrtDCI, &c4_st);
    }

    c4_i6 = (int32_T)c4_c_i;
    if ((c4_i6 < 1) || (c4_i6 > c4_peak_locs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i6, 1, c4_peak_locs_size[0],
        &c4_c_emlrtBCI, &c4_st);
    }

    c4_d_c = c4_peak_locs_data[c4_i6 - 1];
    c4_d2 = (c4_d_c - 3.0) - 2.0;
    c4_d3 = (c4_d_c + 3.0) + 2.0;
    c4_i7 = (int32_T)(c4_d3 + (1.0 - c4_d2));
    emlrtForLoopVectorCheckR2021a(c4_d2, 1.0, c4_d3, mxDOUBLE_CLASS, c4_i7,
      &c4_pb_emlrtRTEI, &c4_st);
    for (c4_idx = 0; c4_idx < c4_i7; c4_idx++) {
      c4_b_idx = c4_d2 + (real_T)c4_idx;
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 1);
      if (covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 1U,
                            c4_b_idx, 1.0, -1, 5U, c4_b_idx >= 1.0)) &&
          covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 1,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 2U,
                            c4_b_idx, 128.0, -1, 3U, c4_b_idx <= 128.0))) {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, true);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1, true);
        c4_dist = c4_b_idx - c4_d_c;
        c4_e_x = c4_dist;
        c4_f_x = c4_e_x;
        c4_g_x = c4_f_x;
        c4_e_y = muDoubleScalarAbs(c4_g_x);
        c4_h_x = c4_dist;
        c4_i_x = c4_h_x;
        c4_j_x = c4_i_x;
        c4_f_y = muDoubleScalarAbs(c4_j_x);
        if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 2,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 3U, c4_e_y,
                            3.0, -1, 3U, c4_f_y <= 3.0))) {
          if (c4_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c4_b_idx)) {
            emlrtIntegerCheckR2012b(c4_b_idx, &c4_b_emlrtDCI, &c4_st);
          }

          c4_i8 = (int32_T)c4_b_idx;
          if ((c4_i8 < 1) || (c4_i8 > 128)) {
            emlrtDynamicBoundsCheckR2012b(c4_i8, 1, 128, &c4_b_emlrtBCI, &c4_st);
          }

          c4_alpha[c4_i8 - 1] = 0.0;
        } else {
          c4_k_x = c4_dist;
          c4_l_x = c4_k_x;
          c4_m_x = c4_l_x;
          c4_g_y = muDoubleScalarAbs(c4_m_x);
          c4_n_x = c4_dist;
          c4_o_x = c4_n_x;
          c4_p_x = c4_o_x;
          c4_h_y = muDoubleScalarAbs(c4_p_x);
          if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 3,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c4_covrtInstance, 4U, 0U, 4U,
                              c4_g_y, 5.0, -1, 3U, c4_h_y <= 5.0))) {
            if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 4,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c4_covrtInstance, 4U, 0U, 5U,
                                c4_dist, 0.0, -1, 2U, c4_dist < 0.0))) {
              c4_rel_idx = ((c4_dist + 3.0) + 2.0) + 1.0;
            } else {
              c4_rel_idx = ((c4_dist - 3.0) + 2.0) + 1.0;
            }

            if (c4_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c4_b_idx)) {
              emlrtIntegerCheckR2012b(c4_b_idx, &c4_d_emlrtDCI, &c4_st);
            }

            c4_i9 = (int32_T)c4_b_idx;
            if ((c4_i9 < 1) || (c4_i9 > 128)) {
              emlrtDynamicBoundsCheckR2012b(c4_i9, 1, 128, &c4_d_emlrtBCI,
                &c4_st);
            }

            c4_varargin_1 = c4_alpha[c4_i9 - 1];
            if (c4_rel_idx != (real_T)(int32_T)muDoubleScalarFloor(c4_rel_idx))
            {
              emlrtIntegerCheckR2012b(c4_rel_idx, &c4_e_emlrtDCI, &c4_st);
            }

            c4_i10 = (int32_T)c4_rel_idx;
            if ((c4_i10 < 1) || (c4_i10 > 5)) {
              emlrtDynamicBoundsCheckR2012b(c4_i10, 1, 5, &c4_e_emlrtBCI, &c4_st);
            }

            c4_varargin_2 = c4_dv[c4_i10 - 1];
            c4_q_x = c4_varargin_1;
            c4_i_y = c4_varargin_2;
            c4_r_x = c4_q_x;
            c4_j_y = c4_i_y;
            c4_s_x = c4_r_x;
            c4_k_y = c4_j_y;
            c4_h_a = c4_s_x;
            c4_d_b = c4_k_y;
            c4_t_x = c4_h_a;
            c4_l_y = c4_d_b;
            c4_u_x = c4_t_x;
            c4_m_y = c4_l_y;
            c4_minval = muDoubleScalarMin(c4_u_x, c4_m_y);
            if (c4_b_idx != (real_T)(int32_T)muDoubleScalarFloor(c4_b_idx)) {
              emlrtIntegerCheckR2012b(c4_b_idx, &c4_emlrtDCI, &c4_st);
            }

            c4_i11 = (int32_T)c4_b_idx;
            if ((c4_i11 < 1) || (c4_i11 > 128)) {
              emlrtDynamicBoundsCheckR2012b(c4_i11, 1, 128, &c4_emlrtBCI, &c4_st);
            }

            c4_alpha[c4_i11 - 1] = c4_minval;
          }
        }
      } else {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, false);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1, false);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 0);
  for (c4_i4 = 0; c4_i4 < 128; c4_i4++) {
    (*chartInstance->c4_a3_smoothed)[c4_i4] = c4_a3_smoothed_full[c4_i4] *
      c4_alpha[c4_i4] + c4_b_a3_in[c4_i4] * (1.0 - c4_alpha[c4_i4]);
  }

  for (c4_i5 = 0; c4_i5 < 128; c4_i5++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                      (*chartInstance->c4_a3_smoothed)[c4_i5]);
  }
}

static void ext_mode_exec_c4_untitled(SFc4_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_jit_animation_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_untitled(SFc4_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(1, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_a3_smoothed, 0,
    0U, 1, 0U, 2, 128, 1), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_untitled(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv[128];
  int32_T c4_i;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "a3_smoothed", c4_dv);
  for (c4_i = 0; c4_i < 128; c4_i++) {
    (*chartInstance->c4_a3_smoothed)[c4_i] = c4_dv[c4_i];
  }

  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void c4_filtfilt(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_varargin_2[128], real_T c4_y[128])
{
  static real_T c4_dv[4] = { 1.0, 0.0, 1.0, -1.0 };

  static real_T c4_B[3] = { 0.068965517241379309, 0.86206896551724133,
    0.068965517241379309 };

  static real_T c4_dv1[2] = { 0.86206896551724133, 0.068965517241379309 };

  static real_T c4_rhs[2] = { 0.86206896551724133, 0.068965517241379309 };

  static int32_T c4_a[4] = { 1, 1, 2, 2 };

  static int32_T c4_e_b[4] = { 1, 2, 2, 1 };

  static char_T c4_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c4_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'f', 'i', 'l',
    't', 'f', 'i', 'l', 't', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
    'i', 'n', 'i', 't', 'e' };

  static char_T c4_cv2[12] = { 'i', 'n', 'p', 'u', 't', ' ', 's', 'i', 'g', 'n',
    'a', 'l' };

  cs_di *c4_b_cxA;
  cs_di *c4_cxA;
  cs_din *c4_N;
  cs_din *c4_b_N;
  cs_dis *c4_S;
  cs_dis *c4_b_S;
  c4_anonymous_function c4_this;
  c4_sFhFjA9rDll2zuJpMfejXjH c4_workspace;
  c4_sparse c4_e_y;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  real_T c4_b_ytemp[140];
  real_T c4_c_ytemp[140];
  real_T c4_d_ytemp[140];
  real_T c4_ytemp[140];
  real_T c4_f_y[2];
  real_T c4_outBuff[2];
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_f_b;
  real_T c4_g_b;
  real_T c4_tol;
  real_T c4_val;
  real_T c4_x;
  int32_T c4_cidxInt[4];
  int32_T c4_ridxInt[4];
  int32_T c4_sortedIndices[4];
  int32_T c4_b_c;
  int32_T c4_b_n;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_c_k;
  int32_T c4_cptr;
  int32_T c4_currRowIdx;
  int32_T c4_d_c;
  int32_T c4_d_k;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_k;
  int32_T c4_idx;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_ridx;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_st.site = &c4_d_emlrtRSI;
  c4_b_st.site = &c4_f_emlrtRSI;
  c4_c_st.site = &c4_g_emlrtRSI;
  c4_d_st.site = &c4_h_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 128)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_varargin_2[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b_b = muDoubleScalarIsInf(c4_b_x);
    c4_b1 = !c4_b_b;
    c4_c_x = c4_x;
    c4_c_b = muDoubleScalarIsNaN(c4_c_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    sf_mex_call(&c4_d_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_c_y, 14, c4_d_y)));
  }

  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.site = &c4_i_emlrtRSI;
  c4_c_st.site = &c4_j_emlrtRSI;
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_array_sparse_Constructor(chartInstance, &c4_e_y);
  for (c4_c_k = 0; c4_c_k < 4; c4_c_k++) {
    c4_d_k = c4_c_k;
    c4_sortedIndices[c4_d_k] = c4_d_k + 1;
  }

  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_workspace.a[c4_i] = c4_a[c4_i];
  }

  for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
    c4_workspace.b[c4_i1] = c4_e_b[c4_i1];
  }

  c4_this.workspace = c4_workspace;
  c4_c_introsort(chartInstance, c4_sortedIndices, c4_this);
  for (c4_e_k = 0; c4_e_k < 4; c4_e_k++) {
    c4_g_k = c4_e_k;
    c4_cidxInt[c4_g_k] = c4_a[c4_sortedIndices[c4_g_k] - 1];
  }

  for (c4_f_k = 0; c4_f_k < 4; c4_f_k++) {
    c4_h_k = c4_f_k;
    c4_ridxInt[c4_h_k] = c4_e_b[c4_sortedIndices[c4_h_k] - 1];
  }

  c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_e_y.d, &c4_emlrtRTEI, 4);
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    c4_e_y.d.vector.data[c4_i2] = 0.0;
  }

  c4_array_int32_T_SetSize(chartInstance, &c4_d_st, &c4_e_y.colidx,
    &c4_emlrtRTEI, 3);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_e_y.colidx.vector.data[c4_i3] = 0;
  }

  c4_e_y.colidx.vector.data[0] = 1;
  c4_array_int32_T_SetSize(chartInstance, &c4_d_st, &c4_e_y.rowidx,
    &c4_emlrtRTEI, 4);
  for (c4_i4 = 0; c4_i4 < 4; c4_i4++) {
    c4_e_y.rowidx.vector.data[c4_i4] = 0;
  }

  c4_cptr = 0;
  for (c4_c = 0; c4_c < 2; c4_c++) {
    c4_b_c = c4_c + 1;
    while ((c4_cptr + 1 <= 4) && (c4_cidxInt[c4_cptr] == c4_b_c)) {
      c4_e_y.rowidx.vector.data[c4_cptr] = c4_ridxInt[c4_cptr];
      c4_cptr++;
    }

    c4_e_y.colidx.vector.data[c4_b_c] = c4_cptr + 1;
  }

  for (c4_i_k = 0; c4_i_k < 4; c4_i_k++) {
    c4_d_k = c4_i_k;
    c4_e_y.d.vector.data[c4_d_k] = c4_dv[c4_sortedIndices[c4_d_k] - 1];
  }

  c4_idx = 0;
  c4_i5 = c4_e_y.colidx.size[0] - 2;
  for (c4_c_c = 0; c4_c_c <= c4_i5; c4_c_c++) {
    c4_d_c = c4_c_c;
    c4_ridx = c4_e_y.colidx.vector.data[c4_d_c] - 1;
    c4_e_y.colidx.vector.data[c4_d_c] = c4_idx + 1;
    while (c4_ridx + 1 < c4_e_y.colidx.vector.data[c4_d_c + 1]) {
      c4_val = 0.0;
      c4_currRowIdx = c4_e_y.rowidx.vector.data[c4_ridx];
      while ((c4_ridx + 1 < c4_e_y.colidx.vector.data[c4_d_c + 1]) &&
             (c4_e_y.rowidx.vector.data[c4_ridx] == c4_currRowIdx)) {
        c4_val += c4_e_y.d.vector.data[c4_ridx];
        c4_ridx++;
      }

      if (c4_val != 0.0) {
        c4_e_y.d.vector.data[c4_idx] = c4_val;
        c4_e_y.rowidx.vector.data[c4_idx] = c4_currRowIdx;
        c4_idx++;
      }
    }
  }

  c4_e_y.colidx.vector.data[c4_e_y.colidx.size[0] - 1] = c4_idx + 1;
  c4_c_st.site = &c4_j_emlrtRSI;
  c4_d_st.site = &c4_l_emlrtRSI;
  c4_e_st.site = &c4_m_emlrtRSI;
  c4_f_st.site = &c4_p_emlrtRSI;
  c4_n = c4_e_y.colidx.vector.data[c4_e_y.colidx.size[0] - 1];
  c4_cxA = makeCXSparseMatrix(c4_n - 1, 2, 2, &c4_e_y.colidx.vector.data[0],
    &c4_e_y.rowidx.vector.data[0], &c4_e_y.d.vector.data[0]);
  c4_S = cs_di_sqr(2, c4_cxA, 0);
  c4_N = cs_di_lu(c4_cxA, c4_S, 1);
  cs_di_spfree(c4_cxA);
  if (c4_N == NULL) {
    c4_f_st.site = &c4_o_emlrtRSI;
    c4_warning(chartInstance, &c4_f_st);
    cs_di_sfree(c4_S);
    cs_di_nfree(c4_N);
    c4_b_n = c4_e_y.colidx.vector.data[c4_e_y.colidx.size[0] - 1];
    c4_b_cxA = makeCXSparseMatrix(c4_b_n - 1, 2, 2, &c4_e_y.colidx.vector.data[0],
      &c4_e_y.rowidx.vector.data[0], &c4_e_y.d.vector.data[0]);
    c4_b_S = cs_di_sqr(2, c4_b_cxA, 1);
    c4_b_N = cs_di_qr(c4_b_cxA, c4_b_S);
    cs_di_spfree(c4_b_cxA);
    qr_rank_di(c4_b_N, &c4_tol);
    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_outBuff[c4_i8] = c4_dv1[c4_i8];
    }

    solve_from_qr_di(c4_b_N, c4_b_S, (double *)&c4_outBuff[0], 2, 2);
    cs_di_sfree(c4_b_S);
    cs_di_nfree(c4_b_N);
  } else {
    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_outBuff[c4_i6] = c4_rhs[c4_i6];
    }

    solve_from_lu_di(c4_N, c4_S, (double *)&c4_outBuff[0], 2);
    cs_di_sfree(c4_S);
    cs_di_nfree(c4_N);
  }

  c4_array_sparse_Destructor(chartInstance, &c4_e_y);
  c4_d = 2.0 * c4_varargin_2[0];
  c4_d1 = 2.0 * c4_varargin_2[127];
  for (c4_i7 = 0; c4_i7 < 6; c4_i7++) {
    c4_ytemp[c4_i7] = c4_d - c4_varargin_2[6 - c4_i7];
  }

  for (c4_i9 = 0; c4_i9 < 128; c4_i9++) {
    c4_ytemp[c4_i9 + 6] = c4_varargin_2[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 6; c4_i10++) {
    c4_ytemp[c4_i10 + 134] = c4_d1 - c4_varargin_2[126 - c4_i10];
  }

  c4_f_b = c4_ytemp[0];
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    c4_f_y[c4_i11] = c4_outBuff[c4_i11] * c4_f_b;
  }

  for (c4_i12 = 0; c4_i12 < 140; c4_i12++) {
    c4_b_ytemp[c4_i12] = c4_ytemp[c4_i12];
  }

  c4_filter(chartInstance, c4_B, c4_b_ytemp, c4_f_y, c4_ytemp);
  for (c4_i13 = 0; c4_i13 < 140; c4_i13++) {
    c4_c_ytemp[c4_i13] = c4_ytemp[139 - c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 140; c4_i14++) {
    c4_ytemp[c4_i14] = c4_c_ytemp[c4_i14];
  }

  c4_g_b = c4_ytemp[0];
  for (c4_i15 = 0; c4_i15 < 2; c4_i15++) {
    c4_outBuff[c4_i15] *= c4_g_b;
  }

  for (c4_i16 = 0; c4_i16 < 140; c4_i16++) {
    c4_d_ytemp[c4_i16] = c4_ytemp[c4_i16];
  }

  c4_filter(chartInstance, c4_B, c4_d_ytemp, c4_outBuff, c4_ytemp);
  for (c4_i17 = 0; c4_i17 < 128; c4_i17++) {
    c4_y[c4_i17] = c4_ytemp[133 - c4_i17];
  }
}

static void c4_introsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp, int32_T c4_b_x[4])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_b_x[c4_i] = c4_x[c4_i];
  }

  c4_c_introsort(chartInstance, c4_b_x, c4_cmp);
}

static void c4_insertionsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp, int32_T c4_b_x[4])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_b_x[c4_i] = c4_x[c4_i];
  }

  c4_d_insertionsort(chartInstance, c4_b_x, c4_cmp);
}

static void c4_check_forloop_overflow_error(SFc4_untitledInstanceStruct
  *chartInstance, const emlrtStack *c4_sp)
{
  static char_T c4_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 34), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
    "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_warning(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp)
{
  static char_T c4_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c4_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 7), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1, 0U, 2, 1, 21),
                false);
  c4_st.site = &c4_r_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static void c4_filter(SFc4_untitledInstanceStruct *chartInstance, real_T c4_b[3],
                      real_T c4_x[140], real_T c4_zi[2], real_T c4_y[140])
{
  real_T c4_as;
  int32_T c4_a;
  int32_T c4_b_a;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_c_j;
  int32_T c4_c_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_naxpy;
  (void)chartInstance;
  for (c4_k = 0; c4_k < 2; c4_k++) {
    c4_b_k = c4_k;
    c4_y[c4_b_k] = c4_zi[c4_b_k];
  }

  memset(&c4_y[2], 0, 138U * sizeof(real_T));
  for (c4_c_k = 0; c4_c_k < 140; c4_c_k++) {
    c4_b_k = c4_c_k;
    c4_a = 140 - c4_b_k;
    if (c4_a < 3) {
      c4_naxpy = c4_a;
    } else {
      c4_naxpy = 3;
    }

    c4_as = c4_x[c4_b_k];
    c4_i = (uint8_T)c4_naxpy;
    for (c4_j = 0; c4_j < c4_i; c4_j++) {
      c4_b_j = c4_j;
      c4_y[c4_b_k + c4_b_j] += c4_as * c4_b[c4_b_j];
    }

    c4_b_a = 139 - c4_b_k;
    if (c4_b_a < 2) {
      c4_naxpy = c4_b_a;
    } else {
      c4_naxpy = 2;
    }

    c4_as = -c4_y[c4_b_k];
    c4_i1 = (uint8_T)c4_naxpy;
    for (c4_c_j = 0; c4_c_j < c4_i1; c4_c_j++) {
      c4_b_j = c4_c_j + 1;
      c4_y[c4_b_k + c4_b_j] += c4_as * 0.0;
    }
  }
}

static void c4_pivot(SFc4_untitledInstanceStruct *chartInstance, const
                     emlrtStack *c4_sp, real_T c4_v[128], int32_T c4_ip, int32_T
                     c4_ia, int32_T c4_ib, real_T c4_b_v[128], int32_T *c4_b_ip,
                     int32_T *c4_reps)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 128; c4_i++) {
    c4_b_v[c4_i] = c4_v[c4_i];
  }

  *c4_b_ip = c4_ip;
  *c4_reps = c4_b_pivot(chartInstance, c4_sp, c4_b_v, c4_b_ip, c4_ia, c4_ib);
}

static void c4_medmed(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
                      [128], int32_T c4_nv, int32_T c4_ia, real_T c4_b_v[128])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 128; c4_i++) {
    c4_b_v[c4_i] = c4_v[c4_i];
  }

  c4_b_medmed(chartInstance, c4_b_v, c4_nv, c4_ia);
}

static int32_T c4_thirdOfFive(SFc4_untitledInstanceStruct *chartInstance, real_T
  c4_v[128], int32_T c4_ia, int32_T c4_ib)
{
  real_T c4_a;
  real_T c4_ab_a;
  real_T c4_ab_b;
  real_T c4_b;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_b_v1;
  real_T c4_b_v2;
  real_T c4_b_v3;
  real_T c4_bb_a;
  real_T c4_bb_b;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_v1;
  real_T c4_c_v2;
  real_T c4_c_v3;
  real_T c4_cb_a;
  real_T c4_cb_b;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_db_a;
  real_T c4_db_b;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_eb_a;
  real_T c4_eb_b;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_j_a;
  real_T c4_j_b;
  real_T c4_k_a;
  real_T c4_k_b;
  real_T c4_l_a;
  real_T c4_l_b;
  real_T c4_m_a;
  real_T c4_m_b;
  real_T c4_n_a;
  real_T c4_n_b;
  real_T c4_o_a;
  real_T c4_o_b;
  real_T c4_p_a;
  real_T c4_p_b;
  real_T c4_q_a;
  real_T c4_q_b;
  real_T c4_r_a;
  real_T c4_r_b;
  real_T c4_s_a;
  real_T c4_s_b;
  real_T c4_t_a;
  real_T c4_t_b;
  real_T c4_u_a;
  real_T c4_u_b;
  real_T c4_v1;
  real_T c4_v2;
  real_T c4_v3;
  real_T c4_v4;
  real_T c4_v5;
  real_T c4_v_a;
  real_T c4_v_b;
  real_T c4_w_a;
  real_T c4_w_b;
  real_T c4_x_a;
  real_T c4_x_b;
  real_T c4_y_a;
  real_T c4_y_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_im;
  int32_T c4_c_i2;
  int32_T c4_c_i3;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_im;
  int32_T c4_j1;
  int32_T c4_j2;
  int32_T c4_j3;
  int32_T c4_j4;
  int32_T c4_j5;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_f_p;
  boolean_T c4_g_p;
  boolean_T c4_h_p;
  boolean_T c4_i_p;
  boolean_T c4_j_p;
  boolean_T c4_k_p;
  boolean_T c4_l_p;
  boolean_T c4_m_p;
  boolean_T c4_n_p;
  boolean_T c4_o_p;
  boolean_T c4_p;
  (void)chartInstance;
  c4_i2 = c4_ia;
  if ((c4_ia == c4_ib) || (c4_i2 + 1 == c4_ib)) {
    c4_im = c4_ia;
  } else {
    c4_i3 = c4_i2 + 2;
    c4_i4 = c4_i3 + 1;
    if ((c4_i3 == c4_ib) || (c4_i4 == c4_ib)) {
      c4_i1 = c4_ia;
      c4_v1 = c4_v[c4_ia - 1];
      c4_b_i2 = c4_i2 + 1;
      c4_v2 = c4_v[c4_i2];
      c4_b_i3 = c4_i3;
      c4_v3 = c4_v[c4_i3 - 1];
      c4_a = c4_v1;
      c4_b = c4_v2;
      c4_c_a = c4_a;
      c4_c_b = c4_b;
      c4_p = (c4_c_a < c4_c_b);
      if (c4_p) {
        c4_f_a = c4_v2;
        c4_f_b = c4_v3;
        c4_j_a = c4_f_a;
        c4_j_b = c4_f_b;
        c4_d_p = (c4_j_a < c4_j_b);
        if (c4_d_p) {
          c4_b_im = c4_b_i2;
        } else {
          c4_n_a = c4_v1;
          c4_n_b = c4_v3;
          c4_r_a = c4_n_a;
          c4_r_b = c4_n_b;
          c4_h_p = (c4_r_a < c4_r_b);
          if (c4_h_p) {
            c4_b_im = c4_b_i3;
          } else {
            c4_b_im = c4_i1;
          }
        }
      } else {
        c4_e_a = c4_v1;
        c4_e_b = c4_v3;
        c4_i_a = c4_e_a;
        c4_i_b = c4_e_b;
        c4_c_p = (c4_i_a < c4_i_b);
        if (c4_c_p) {
          c4_b_im = c4_i1;
        } else {
          c4_m_a = c4_v2;
          c4_m_b = c4_v3;
          c4_q_a = c4_m_a;
          c4_q_b = c4_m_b;
          c4_g_p = (c4_q_a < c4_q_b);
          if (c4_g_p) {
            c4_b_im = c4_b_i3;
          } else {
            c4_b_im = c4_b_i2;
          }
        }
      }

      c4_im = c4_b_im;
    } else {
      c4_i5 = c4_i4;
      c4_b_i1 = c4_ia;
      c4_b_v1 = c4_v[c4_ia - 1];
      c4_c_i2 = c4_i2 + 1;
      c4_b_v2 = c4_v[c4_i2];
      c4_c_i3 = c4_i3;
      c4_b_v3 = c4_v[c4_i3 - 1];
      c4_b_a = c4_b_v1;
      c4_b_b = c4_b_v2;
      c4_d_a = c4_b_a;
      c4_d_b = c4_b_b;
      c4_b_p = (c4_d_a < c4_d_b);
      if (c4_b_p) {
        c4_h_a = c4_b_v2;
        c4_h_b = c4_b_v3;
        c4_l_a = c4_h_a;
        c4_l_b = c4_h_b;
        c4_f_p = (c4_l_a < c4_l_b);
        if (c4_f_p) {
          c4_j1 = c4_b_i1;
          c4_j2 = c4_c_i2;
          c4_j3 = c4_c_i3;
        } else {
          c4_p_a = c4_b_v1;
          c4_p_b = c4_b_v3;
          c4_t_a = c4_p_a;
          c4_t_b = c4_p_b;
          c4_j_p = (c4_t_a < c4_t_b);
          if (c4_j_p) {
            c4_j1 = c4_b_i1;
            c4_j2 = c4_c_i3;
            c4_j3 = c4_c_i2;
          } else {
            c4_j1 = c4_c_i3;
            c4_j2 = c4_b_i1;
            c4_j3 = c4_c_i2;
          }
        }
      } else {
        c4_g_a = c4_b_v1;
        c4_g_b = c4_b_v3;
        c4_k_a = c4_g_a;
        c4_k_b = c4_g_b;
        c4_e_p = (c4_k_a < c4_k_b);
        if (c4_e_p) {
          c4_j1 = c4_c_i2;
          c4_j2 = c4_b_i1;
          c4_j3 = c4_c_i3;
        } else {
          c4_o_a = c4_b_v2;
          c4_o_b = c4_b_v3;
          c4_s_a = c4_o_a;
          c4_s_b = c4_o_b;
          c4_i_p = (c4_s_a < c4_s_b);
          if (c4_i_p) {
            c4_j1 = c4_c_i2;
            c4_j2 = c4_c_i3;
            c4_j3 = c4_b_i1;
          } else {
            c4_j1 = c4_c_i3;
            c4_j2 = c4_c_i2;
            c4_j3 = c4_b_i1;
          }
        }
      }

      c4_j4 = c4_i4;
      c4_j5 = c4_i5 + 1;
      c4_c_v1 = c4_v[c4_j1 - 1];
      c4_c_v2 = c4_v[c4_j2 - 1];
      c4_c_v3 = c4_v[c4_j3 - 1];
      c4_v4 = c4_v[c4_i4 - 1];
      c4_v5 = c4_v[c4_i5];
      c4_u_a = c4_v5;
      c4_u_b = c4_v4;
      c4_v_a = c4_u_a;
      c4_v_b = c4_u_b;
      c4_k_p = (c4_v_a < c4_v_b);
      if (c4_k_p) {
        c4_j4 = c4_i5 + 1;
        c4_j5 = c4_i4;
        c4_v5 = c4_v4;
        c4_v4 = c4_v[c4_i5];
      }

      c4_w_a = c4_v5;
      c4_w_b = c4_c_v1;
      c4_x_a = c4_w_a;
      c4_x_b = c4_w_b;
      c4_l_p = (c4_x_a < c4_x_b);
      if (c4_l_p) {
        c4_im = c4_j1;
      } else {
        c4_y_a = c4_v5;
        c4_y_b = c4_c_v2;
        c4_ab_a = c4_y_a;
        c4_ab_b = c4_y_b;
        c4_m_p = (c4_ab_a < c4_ab_b);
        if (c4_m_p) {
          c4_im = c4_j5;
        } else {
          c4_bb_a = c4_v4;
          c4_bb_b = c4_c_v2;
          c4_cb_a = c4_bb_a;
          c4_cb_b = c4_bb_b;
          c4_n_p = (c4_cb_a < c4_cb_b);
          if (c4_n_p) {
            c4_im = c4_j2;
          } else {
            c4_db_a = c4_v4;
            c4_db_b = c4_c_v3;
            c4_eb_a = c4_db_a;
            c4_eb_b = c4_db_b;
            c4_o_p = (c4_eb_a < c4_eb_b);
            if (c4_o_p) {
              c4_im = c4_j4;
            } else {
              c4_im = c4_j3;
            }
          }
        }
      }
    }
  }

  return c4_im;
}

static void c4_med3(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v[128],
                    int32_T c4_nv, int32_T c4_ia, int32_T c4_ib, real_T c4_b_v
                    [128])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 128; c4_i++) {
    c4_b_v[c4_i] = c4_v[c4_i];
  }

  c4_b_med3(chartInstance, c4_b_v, c4_nv, c4_ia, c4_ib);
}

static void c4_findpeaks(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[128], real_T c4_varargin_2, real_T
  c4_Ypk_data[], int32_T c4_Ypk_size[1], real_T c4_Xpk_data[], int32_T
  c4_Xpk_size[1])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_b_locs_temp_data[256];
  real_T c4_locs_temp_data[256];
  real_T c4_pks_data[256];
  real_T c4_dv[2];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_jj;
  real_T c4_b_minH;
  real_T c4_b_varargin_2;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_base;
  real_T c4_c_a;
  real_T c4_c_varargin_2;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d_b;
  real_T c4_d_i;
  real_T c4_d_varargin_2;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_e_varargin_2;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_f_x;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_g_x;
  real_T c4_h_a;
  real_T c4_h_x;
  real_T c4_i_b;
  real_T c4_i_x;
  real_T c4_j_b;
  real_T c4_k_b;
  real_T c4_minH;
  real_T c4_pk;
  real_T c4_varargin_1;
  real_T c4_x;
  real_T c4_y;
  real_T c4_yk;
  real_T c4_ykfirst;
  int32_T c4_c_data[256];
  int32_T c4_iPk_data[256];
  int32_T c4_sortIdx_data[256];
  int32_T c4_b_iPk_data[128];
  int32_T c4_fPk_data[128];
  int32_T c4_iFinite_data[128];
  int32_T c4_iInfinite_data[128];
  int32_T c4_iv[2];
  int32_T c4_b_iPk_size[1];
  int32_T c4_b_locs_temp_size[1];
  int32_T c4_c_size[1];
  int32_T c4_fPk_size[1];
  int32_T c4_iFinite_size[1];
  int32_T c4_iInfinite_size[1];
  int32_T c4_iPk_size[1];
  int32_T c4_idelete_size[1];
  int32_T c4_iv1[1];
  int32_T c4_locs_temp_size[1];
  int32_T c4_pks_size[1];
  int32_T c4_sortIdx_size[1];
  int32_T c4_b_i;
  int32_T c4_b_i2;
  int32_T c4_b_idx1;
  int32_T c4_b_idx2;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_b_nPk;
  int32_T c4_b_varargin_1;
  int32_T c4_c;
  int32_T c4_c_i;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_p;
  int32_T c4_c_varargin_1;
  int32_T c4_d_a;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_varargin_1;
  int32_T c4_e_i;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_e_varargin_1;
  int32_T c4_end;
  int32_T c4_f_i;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_j;
  int32_T c4_j_loop_ub;
  int32_T c4_jj;
  int32_T c4_k;
  int32_T c4_kEnd;
  int32_T c4_kfirst;
  int32_T c4_locs_temp;
  int32_T c4_loop_ub;
  int32_T c4_n;
  int32_T c4_nInf;
  int32_T c4_nInflect;
  int32_T c4_nPk;
  int32_T c4_np1;
  int32_T c4_pEnd;
  int32_T c4_partialTrueCount;
  int32_T c4_q;
  int32_T c4_qEnd;
  int32_T c4_trueCount;
  char_T c4_dir;
  char_T c4_previousdir;
  boolean_T c4_idelete_data[256];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b8;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_f_p;
  boolean_T c4_g_p;
  boolean_T c4_h_b;
  boolean_T c4_isinfyk;
  boolean_T c4_isinfykfirst;
  boolean_T c4_l_b;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ab_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_b_varargin_2 = c4_varargin_2;
  c4_c_varargin_2 = c4_b_varargin_2;
  c4_d_varargin_2 = c4_c_varargin_2;
  c4_minH = c4_d_varargin_2;
  c4_st.site = &c4_bb_emlrtRSI;
  c4_nPk = 0;
  c4_nInf = 0;
  c4_nInflect = 0;
  c4_dir = 'n';
  c4_kfirst = 0;
  c4_ykfirst = rtInf;
  c4_isinfykfirst = true;
  for (c4_k = 0; c4_k < 128; c4_k++) {
    c4_yk = c4_Yin[c4_k];
    c4_x = c4_yk;
    c4_b_b = muDoubleScalarIsNaN(c4_x);
    if (c4_b_b) {
      c4_yk = rtInf;
      c4_isinfyk = true;
    } else {
      c4_b_x = c4_yk;
      c4_c_b = muDoubleScalarIsInf(c4_b_x);
      if (c4_c_b && (c4_yk > 0.0)) {
        c4_isinfyk = true;
        c4_nInf++;
        if ((c4_nInf < 1) || (c4_nInf > 128)) {
          emlrtDynamicBoundsCheckR2012b(c4_nInf, 1, 128, &c4_j_emlrtBCI, &c4_st);
        }

        c4_iInfinite_data[c4_nInf - 1] = c4_k + 1;
      } else {
        c4_isinfyk = false;
      }
    }

    if (c4_yk != c4_ykfirst) {
      c4_previousdir = c4_dir;
      if (c4_isinfyk || c4_isinfykfirst) {
        c4_dir = 'n';
        if (c4_kfirst >= 1) {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 128, &c4_p_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
        }
      } else if (c4_yk < c4_ykfirst) {
        c4_dir = 'd';
        if (c4_previousdir != 'd') {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 128, &c4_o_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
          if (c4_previousdir == 'i') {
            c4_nPk++;
            if ((c4_nPk < 1) || (c4_nPk > 128)) {
              emlrtDynamicBoundsCheckR2012b(c4_nPk, 1, 128, &c4_l_emlrtBCI,
                &c4_st);
            }

            c4_iFinite_data[c4_nPk - 1] = c4_kfirst;
          }
        }
      } else {
        c4_dir = 'i';
        if (c4_previousdir != 'i') {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 128)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 128, &c4_n_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
        }
      }

      c4_ykfirst = c4_yk;
      c4_kfirst = c4_k + 1;
      c4_isinfykfirst = c4_isinfyk;
    }
  }

  if ((!c4_isinfykfirst) && ((c4_nInflect == 0) || (c4_fPk_data[c4_nInflect - 1]
        < 128))) {
    c4_nInflect++;
    if ((c4_nInflect < 1) || (c4_nInflect > 128)) {
      emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 128, &c4_m_emlrtBCI, &c4_st);
    }
  }

  c4_b = (c4_nPk < 1);
  if (c4_b) {
    c4_i = -1;
  } else {
    if ((c4_nPk < 1) || (c4_nPk > 128)) {
      emlrtDynamicBoundsCheckR2012b(c4_nPk, 1, 128, &c4_k_emlrtBCI, &c4_st);
    }

    c4_i = c4_nPk - 1;
  }

  c4_iFinite_size[0] = c4_i + 1;
  c4_b1 = (c4_nInf < 1);
  if (c4_b1) {
    c4_i1 = -1;
  } else {
    if ((c4_nInf < 1) || (c4_nInf > 128)) {
      emlrtDynamicBoundsCheckR2012b(c4_nInf, 1, 128, &c4_i_emlrtBCI, &c4_st);
    }

    c4_i1 = c4_nInf - 1;
  }

  c4_iInfinite_size[0] = c4_i1 + 1;
  c4_b2 = (c4_nInflect < 1);
  if ((!c4_b2) && ((c4_nInflect < 1) || (c4_nInflect > 128))) {
    emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 128, &c4_h_emlrtBCI, &c4_st);
  }

  c4_st.site = &c4_cb_emlrtRSI;
  c4_b_minH = c4_minH;
  c4_iPk_size[0] = c4_iFinite_size[0];
  c4_b_nPk = 0;
  c4_n = c4_iFinite_size[0];
  c4_i2 = (uint8_T)c4_n;
  for (c4_b_k = 0; c4_b_k < c4_i2; c4_b_k++) {
    c4_c_k = c4_b_k;
    c4_i3 = c4_c_k + 1;
    if ((c4_i3 < 1) || (c4_i3 > c4_iFinite_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i3, 1, c4_iFinite_size[0], &c4_s_emlrtBCI,
        &c4_st);
    }

    c4_j = c4_iFinite_data[c4_i3 - 1];
    if ((c4_j < 1) || (c4_j > 128)) {
      emlrtDynamicBoundsCheckR2012b(c4_j, 1, 128, &c4_t_emlrtBCI, &c4_st);
    }

    c4_pk = c4_Yin[c4_j - 1];
    if (c4_pk > c4_b_minH) {
      c4_i6 = c4_j - 1;
      if ((c4_i6 < 1) || (c4_i6 > 128)) {
        emlrtDynamicBoundsCheckR2012b(c4_i6, 1, 128, &c4_u_emlrtBCI, &c4_st);
      }

      c4_varargin_1 = c4_Yin[c4_i6 - 1];
      c4_i8 = c4_j + 1;
      if ((c4_i8 < 1) || (c4_i8 > 128)) {
        emlrtDynamicBoundsCheckR2012b(c4_i8, 1, 128, &c4_v_emlrtBCI, &c4_st);
      }

      c4_e_varargin_2 = c4_Yin[c4_i8 - 1];
      c4_c_x = c4_varargin_1;
      c4_y = c4_e_varargin_2;
      c4_d_x = c4_c_x;
      c4_b_y = c4_y;
      c4_e_x = c4_d_x;
      c4_c_y = c4_b_y;
      c4_a = c4_e_x;
      c4_d_b = c4_c_y;
      c4_f_x = c4_a;
      c4_d_y = c4_d_b;
      c4_g_x = c4_f_x;
      c4_e_y = c4_d_y;
      c4_base = muDoubleScalarMax(c4_g_x, c4_e_y);
      if (c4_pk - c4_base >= 0.0) {
        c4_b_nPk++;
        if ((c4_b_nPk < 1) || (c4_b_nPk > c4_iPk_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c4_b_nPk, 1, c4_iPk_size[0],
            &c4_w_emlrtBCI, &c4_st);
        }

        c4_b_iPk_data[c4_b_nPk - 1] = c4_j;
      }
    }
  }

  c4_b3 = (c4_b_nPk < 1);
  if (c4_b3) {
    c4_i4 = 0;
  } else {
    if (c4_iPk_size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_iPk_size[0], &c4_g_emlrtBCI, &c4_st);
    }

    if ((c4_b_nPk < 1) || (c4_b_nPk > c4_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_b_nPk, 1, c4_iPk_size[0], &c4_f_emlrtBCI,
        &c4_st);
    }

    c4_i4 = c4_b_nPk;
  }

  c4_iPk_size[0] = c4_i4;
  c4_b_iPk_size[0] = c4_iPk_size[0];
  c4_loop_ub = c4_iPk_size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_loop_ub; c4_i5++) {
    c4_iPk_data[c4_i5] = c4_b_iPk_data[c4_i5];
  }

  c4_st.site = &c4_db_emlrtRSI;
  c4_iPk_size[0] = c4_b_iPk_size[0];
  c4_b_loop_ub = c4_b_iPk_size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
    c4_b_iPk_data[c4_i7] = c4_iPk_data[c4_i7];
  }

  c4_b_st.site = &c4_hb_emlrtRSI;
  c4_c_st.site = &c4_ib_emlrtRSI;
  c4_d_st.site = &c4_jb_emlrtRSI;
  c4_do_vectors(chartInstance, &c4_d_st, c4_b_iPk_data, c4_iPk_size,
                c4_iInfinite_data, c4_iInfinite_size, c4_c_data, c4_c_size,
                c4_fPk_data, c4_fPk_size, c4_iFinite_data, c4_iFinite_size);
  c4_st.site = &c4_eb_emlrtRSI;
  if (c4_c_size[0] == 0) {
    c4_b_st.site = &c4_kb_emlrtRSI;
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_b_iPk_size[0] = 0;
  } else {
    c4_pks_size[0] = c4_c_size[0];
    c4_c_loop_ub = c4_c_size[0] - 1;
    for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
      c4_pks_data[c4_i9] = c4_Yin[c4_c_data[c4_i9] - 1];
    }

    c4_locs_temp_size[0] = c4_c_size[0];
    c4_d_loop_ub = c4_c_size[0] - 1;
    for (c4_i10 = 0; c4_i10 <= c4_d_loop_ub; c4_i10++) {
      c4_locs_temp_data[c4_i10] = 1.0 + (real_T)(c4_c_data[c4_i10] - 1);
    }

    c4_sortIdx_size[0] = c4_pks_size[0];
    c4_b_n = c4_pks_size[0];
    c4_np1 = c4_b_n + 1;
    c4_i11 = c4_b_n;
    for (c4_d_k = 1; c4_d_k <= c4_i11 - 1; c4_d_k += 2) {
      c4_idx1 = c4_d_k - 1;
      c4_idx2 = c4_d_k;
      c4_b_a = c4_pks_data[c4_idx1];
      c4_e_b = c4_pks_data[c4_idx2];
      c4_c_a = c4_b_a;
      c4_f_b = c4_e_b;
      c4_e_a = c4_c_a;
      c4_g_b = c4_f_b;
      c4_p = (c4_e_a >= c4_g_b);
      if (c4_p) {
        c4_b_p = true;
      } else {
        c4_h_x = c4_c_a;
        c4_h_b = muDoubleScalarIsNaN(c4_h_x);
        if (c4_h_b) {
          c4_b_p = true;
        } else {
          c4_b_p = false;
        }
      }

      c4_d_p = c4_b_p;
      if (c4_d_p) {
        c4_sortIdx_data[c4_d_k - 1] = c4_d_k;
        c4_sortIdx_data[c4_d_k] = c4_d_k + 1;
      } else {
        c4_sortIdx_data[c4_d_k - 1] = c4_d_k + 1;
        c4_sortIdx_data[c4_d_k] = c4_d_k;
      }
    }

    if ((c4_b_n & 1) != 0) {
      c4_sortIdx_data[c4_b_n - 1] = c4_b_n;
    }

    c4_b_i = 2;
    while (c4_b_i < c4_b_n) {
      c4_d_a = c4_b_i;
      c4_b_i2 = c4_d_a << 1;
      c4_b_j = 1;
      for (c4_pEnd = 1 + c4_b_i; c4_pEnd < c4_np1; c4_pEnd = c4_qEnd + c4_b_i) {
        c4_c_p = c4_b_j - 1;
        c4_q = c4_pEnd - 1;
        c4_qEnd = c4_b_j + c4_b_i2;
        if (c4_qEnd > c4_np1) {
          c4_qEnd = c4_np1;
        }

        c4_e_k = 0;
        c4_kEnd = c4_qEnd - c4_b_j;
        while (c4_e_k + 1 <= c4_kEnd) {
          c4_b_idx1 = c4_sortIdx_data[c4_c_p] - 1;
          c4_b_idx2 = c4_sortIdx_data[c4_q] - 1;
          c4_f_a = c4_pks_data[c4_b_idx1];
          c4_i_b = c4_pks_data[c4_b_idx2];
          c4_g_a = c4_f_a;
          c4_j_b = c4_i_b;
          c4_h_a = c4_g_a;
          c4_k_b = c4_j_b;
          c4_e_p = (c4_h_a >= c4_k_b);
          if (c4_e_p) {
            c4_f_p = true;
          } else {
            c4_i_x = c4_g_a;
            c4_l_b = muDoubleScalarIsNaN(c4_i_x);
            if (c4_l_b) {
              c4_f_p = true;
            } else {
              c4_f_p = false;
            }
          }

          c4_g_p = c4_f_p;
          if (c4_g_p) {
            c4_iPk_data[c4_e_k] = c4_sortIdx_data[c4_c_p];
            c4_c_p++;
            if (c4_c_p + 1 == c4_pEnd) {
              while (c4_q + 1 < c4_qEnd) {
                c4_e_k++;
                c4_iPk_data[c4_e_k] = c4_sortIdx_data[c4_q];
                c4_q++;
              }
            }
          } else {
            c4_iPk_data[c4_e_k] = c4_sortIdx_data[c4_q];
            c4_q++;
            if (c4_q + 1 == c4_qEnd) {
              while (c4_c_p + 1 < c4_pEnd) {
                c4_e_k++;
                c4_iPk_data[c4_e_k] = c4_sortIdx_data[c4_c_p];
                c4_c_p++;
              }
            }
          }

          c4_e_k++;
        }

        c4_c_p = c4_b_j - 2;
        for (c4_f_k = 0; c4_f_k < c4_kEnd; c4_f_k++) {
          c4_e_k = c4_f_k;
          c4_sortIdx_data[(c4_c_p + c4_e_k) + 1] = c4_iPk_data[c4_e_k];
        }

        c4_b_j = c4_qEnd;
      }

      c4_b_i = c4_b_i2;
    }

    c4_locs_temp = c4_locs_temp_size[0];
    c4_b_locs_temp_size[0] = c4_sortIdx_size[0];
    c4_f_loop_ub = c4_sortIdx_size[0] - 1;
    for (c4_i16 = 0; c4_i16 <= c4_f_loop_ub; c4_i16++) {
      if ((c4_sortIdx_data[c4_i16] < 1) || (c4_sortIdx_data[c4_i16] >
           c4_locs_temp)) {
        emlrtDynamicBoundsCheckR2012b(c4_sortIdx_data[c4_i16], 1, c4_locs_temp,
          &c4_x_emlrtBCI, &c4_st);
      }

      c4_b_locs_temp_data[c4_i16] = c4_locs_temp_data[c4_sortIdx_data[c4_i16] -
        1];
    }

    c4_locs_temp_size[0] = c4_b_locs_temp_size[0];
    c4_h_loop_ub = c4_b_locs_temp_size[0] - 1;
    for (c4_i18 = 0; c4_i18 <= c4_h_loop_ub; c4_i18++) {
      c4_locs_temp_data[c4_i18] = c4_b_locs_temp_data[c4_i18];
    }

    c4_dv[0] = (real_T)c4_locs_temp_size[0];
    c4_idelete_size[0] = (int32_T)c4_dv[0];
    c4_j_loop_ub = (int32_T)c4_dv[0] - 1;
    if (c4_j_loop_ub >= 0) {
      memset(&c4_idelete_data[0], 0, (uint32_T)(c4_j_loop_ub + 1) * sizeof
             (boolean_T));
    }

    c4_iv1[0] = (int32_T)c4_dv[0];
    c4_b_varargin_1 = c4_iv1[0];
    c4_c_varargin_1 = c4_b_varargin_1;
    c4_d1 = (real_T)c4_c_varargin_1;
    c4_i20 = (int32_T)c4_d1;
    for (c4_c_i = 0; c4_c_i < c4_i20; c4_c_i++) {
      c4_d_i = (real_T)c4_c_i + 1.0;
      c4_i21 = (int32_T)c4_d_i;
      if ((c4_i21 < 1) || (c4_i21 > c4_idelete_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_i21, 1, c4_idelete_size[0],
          &c4_ab_emlrtBCI, &c4_st);
      }

      if (!c4_idelete_data[c4_i21 - 1]) {
        c4_d_varargin_1 = c4_idelete_size[0];
        c4_e_varargin_1 = c4_d_varargin_1;
        c4_d2 = (real_T)c4_e_varargin_1;
        c4_i22 = (int32_T)-((-1.0 - c4_d2) + 1.0);
        emlrtForLoopVectorCheckR2021a(c4_d2, -1.0, 1.0, mxDOUBLE_CLASS, c4_i22,
          &c4_rb_emlrtRTEI, &c4_st);
        for (c4_jj = 0; c4_jj < c4_i22; c4_jj++) {
          c4_b_jj = c4_d2 - (real_T)c4_jj;
          c4_i26 = (int32_T)c4_b_jj;
          if ((c4_i26 < 1) || (c4_i26 > c4_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i26, 1, c4_idelete_size[0],
              &c4_db_emlrtBCI, &c4_st);
          }

          c4_b5 = c4_idelete_data[c4_i26 - 1];
          c4_i27 = (int32_T)c4_b_jj;
          if ((c4_i27 < 1) || (c4_i27 > c4_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_locs_temp_size[0],
              &c4_eb_emlrtBCI, &c4_st);
          }

          c4_i28 = (int32_T)c4_d_i;
          if ((c4_i28 < 1) || (c4_i28 > c4_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i28, 1, c4_locs_temp_size[0],
              &c4_fb_emlrtBCI, &c4_st);
          }

          c4_b6 = (c4_locs_temp_data[c4_i27 - 1] >= c4_locs_temp_data[c4_i28 - 1]
                   - 31.0);
          c4_i29 = (int32_T)c4_b_jj;
          if ((c4_i29 < 1) || (c4_i29 > c4_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i29, 1, c4_locs_temp_size[0],
              &c4_gb_emlrtBCI, &c4_st);
          }

          c4_i30 = (int32_T)c4_d_i;
          if ((c4_i30 < 1) || (c4_i30 > c4_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i30, 1, c4_locs_temp_size[0],
              &c4_hb_emlrtBCI, &c4_st);
          }

          c4_b7 = (c4_locs_temp_data[c4_i29 - 1] <= c4_locs_temp_data[c4_i30 - 1]
                   + 31.0);
          c4_b8 = (c4_b6 && c4_b7);
          c4_i31 = (int32_T)c4_b_jj;
          if ((c4_i31 < 1) || (c4_i31 > c4_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i31, 1, c4_idelete_size[0],
              &c4_ib_emlrtBCI, &c4_st);
          }

          c4_idelete_data[c4_i31 - 1] = (c4_b5 || c4_b8);
        }

        c4_i25 = (int32_T)c4_d_i;
        if ((c4_i25 < 1) || (c4_i25 > c4_idelete_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c4_i25, 1, c4_idelete_size[0],
            &c4_cb_emlrtBCI, &c4_st);
        }

        c4_idelete_data[c4_i25 - 1] = false;
      }
    }

    c4_end = c4_idelete_size[0];
    c4_trueCount = 0;
    for (c4_e_i = 0; c4_e_i < c4_end; c4_e_i++) {
      if (!c4_idelete_data[c4_e_i]) {
        c4_trueCount++;
      }
    }

    c4_b_iPk_size[0] = c4_trueCount;
    c4_partialTrueCount = 0;
    for (c4_f_i = 0; c4_f_i < c4_end; c4_f_i++) {
      if (!c4_idelete_data[c4_f_i]) {
        c4_i24 = c4_sortIdx_size[0] - 1;
        if ((c4_f_i < 0) || (c4_f_i > c4_i24)) {
          emlrtDynamicBoundsCheckR2012b(c4_f_i, 0, c4_i24, &c4_bb_emlrtBCI,
            &c4_st);
        }

        c4_iPk_data[c4_partialTrueCount] = c4_sortIdx_data[c4_f_i];
        c4_partialTrueCount++;
      }
    }

    if (c4_b_iPk_size[0] == 0) {
    } else {
      c4_i23 = c4_b_iPk_size[0];
      c4_b_st.site = &c4_lb_emlrtRSI;
      c4_d_introsort(chartInstance, &c4_b_st, c4_iPk_data, c4_i23);
    }
  }

  if (c4_b_iPk_size[0] > 128) {
    c4_fPk_size[0] = 128;
    c4_st.site = &c4_fb_emlrtRSI;
    c4_indexShapeCheck(chartInstance);
    c4_b_iPk_size[0] = 128;
  } else {
    c4_dv[0] = (real_T)c4_b_iPk_size[0];
    c4_fPk_size[0] = (int32_T)c4_dv[0];
  }

  c4_d = (real_T)c4_fPk_size[0];
  c4_b4 = (c4_d < 1.0);
  if (c4_b4) {
    c4_i13 = 0;
  } else {
    c4_i12 = 1;
    if ((c4_i12 < 1) || (c4_i12 > c4_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_b_iPk_size[0], &c4_r_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i14 = (int32_T)c4_d;
    if ((c4_i14 < 1) || (c4_i14 > c4_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i14, 1, c4_b_iPk_size[0], &c4_q_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i13 = c4_i14;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i13;
  c4_st.site = &c4_gb_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_st, c4_b_iPk_size[0], c4_iv);
  c4_c = c4_c_size[0];
  c4_fPk_size[0] = c4_i13;
  c4_e_loop_ub = c4_i13 - 1;
  for (c4_i15 = 0; c4_i15 <= c4_e_loop_ub; c4_i15++) {
    if ((c4_iPk_data[c4_i15] < 1) || (c4_iPk_data[c4_i15] > c4_c)) {
      emlrtDynamicBoundsCheckR2012b(c4_iPk_data[c4_i15], 1, c4_c, &c4_y_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_fPk_data[c4_i15] = c4_c_data[c4_iPk_data[c4_i15] - 1];
  }

  c4_Ypk_size[0] = c4_fPk_size[0];
  c4_g_loop_ub = c4_fPk_size[0] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_g_loop_ub; c4_i17++) {
    c4_Ypk_data[c4_i17] = c4_Yin[c4_fPk_data[c4_i17] - 1];
  }

  c4_Xpk_size[0] = c4_fPk_size[0];
  c4_i_loop_ub = c4_fPk_size[0] - 1;
  for (c4_i19 = 0; c4_i19 <= c4_i_loop_ub; c4_i19++) {
    c4_Xpk_data[c4_i19] = 1.0 + (real_T)(c4_fPk_data[c4_i19] - 1);
  }
}

static void c4_do_vectors(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_a_data[], int32_T c4_a_size[1], int32_T
  c4_b_data[], int32_T c4_b_size[1], int32_T c4_c_data[], int32_T c4_c_size[1],
  int32_T c4_ia_data[], int32_T c4_ia_size[1], int32_T c4_ib_data[], int32_T
  c4_ib_size[1])
{
  static char_T c4_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'A' };

  static char_T c4_cv1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'B' };

  static char_T c4_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_iv[2];
  int32_T c4_a;
  int32_T c4_ab_a;
  int32_T c4_ak;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_ak;
  int32_T c4_b_bk;
  int32_T c4_b_c;
  int32_T c4_b_ialast;
  int32_T c4_b_iblast;
  int32_T c4_b_k;
  int32_T c4_b_nx;
  int32_T c4_b_xkplus;
  int32_T c4_bb_a;
  int32_T c4_bk;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_c;
  int32_T c4_c_ialast;
  int32_T c4_c_iblast;
  int32_T c4_c_k;
  int32_T c4_c_nx;
  int32_T c4_c_xkplus;
  int32_T c4_cb_a;
  int32_T c4_d_a;
  int32_T c4_d_b;
  int32_T c4_d_c;
  int32_T c4_d_k;
  int32_T c4_d_nx;
  int32_T c4_d_xkplus;
  int32_T c4_db_a;
  int32_T c4_e_a;
  int32_T c4_e_b;
  int32_T c4_eb_a;
  int32_T c4_f_a;
  int32_T c4_f_b;
  int32_T c4_fb_a;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_gb_a;
  int32_T c4_h_a;
  int32_T c4_h_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i_a;
  int32_T c4_i_b;
  int32_T c4_iafirst;
  int32_T c4_ialast;
  int32_T c4_ibfirst;
  int32_T c4_iblast;
  int32_T c4_j_a;
  int32_T c4_k;
  int32_T c4_k_a;
  int32_T c4_l_a;
  int32_T c4_m_a;
  int32_T c4_n_a;
  int32_T c4_na;
  int32_T c4_nb;
  int32_T c4_nc;
  int32_T c4_ncmax;
  int32_T c4_nia;
  int32_T c4_nib;
  int32_T c4_nx;
  int32_T c4_o_a;
  int32_T c4_p_a;
  int32_T c4_q_a;
  int32_T c4_r_a;
  int32_T c4_s_a;
  int32_T c4_t_a;
  int32_T c4_u_a;
  int32_T c4_v_a;
  int32_T c4_w_a;
  int32_T c4_x_a;
  int32_T c4_xkplus;
  int32_T c4_y_a;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_p;
  boolean_T c4_p;
  c4_na = c4_a_size[0];
  c4_nb = c4_b_size[0];
  c4_a = c4_na;
  c4_b = c4_nb;
  c4_ncmax = c4_a + c4_b;
  c4_iv[0] = c4_ncmax;
  c4_c_size[0] = c4_iv[0];
  c4_ia_size[0] = c4_na;
  c4_ib_size[0] = c4_nb;
  if (!c4_issorted(chartInstance, c4_a_data, c4_a_size)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  if (!c4_issorted(chartInstance, c4_b_data, c4_b_size)) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_d_y)));
  }

  c4_nc = -1;
  c4_nia = -1;
  c4_nib = 0;
  c4_iafirst = 1;
  c4_ialast = 1;
  c4_ibfirst = 1;
  c4_iblast = 1;
  while ((c4_ialast <= c4_na) && (c4_iblast <= c4_nb)) {
    c4_k = c4_ialast;
    c4_b_ialast = c4_k;
    c4_nx = c4_a_size[0];
    c4_ak = c4_a_data[c4_b_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_ialast < c4_nx)) {
      c4_b_a = c4_b_ialast + 1;
      c4_c = c4_b_a - 1;
      c4_xkplus = c4_a_data[c4_c];
      c4_e_a = c4_xkplus;
      c4_c_b = c4_ak;
      c4_p = (c4_e_a == c4_c_b);
      if (c4_p) {
        c4_l_a = c4_b_ialast + 1;
        c4_b_ialast = c4_l_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_ialast = c4_b_ialast;
    c4_d_k = c4_iblast;
    c4_c_iblast = c4_d_k;
    c4_d_nx = c4_b_size[0];
    c4_b_bk = c4_b_data[c4_c_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_iblast < c4_d_nx)) {
      c4_n_a = c4_c_iblast + 1;
      c4_d_c = c4_n_a - 1;
      c4_d_xkplus = c4_b_data[c4_d_c];
      c4_s_a = c4_d_xkplus;
      c4_g_b = c4_b_bk;
      c4_e_p = (c4_s_a == c4_g_b);
      if (c4_e_p) {
        c4_w_a = c4_c_iblast + 1;
        c4_c_iblast = c4_w_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_iblast = c4_c_iblast;
    c4_p_a = c4_ak;
    c4_f_b = c4_b_bk;
    c4_d_p = (c4_p_a == c4_f_b);
    if (c4_d_p) {
      c4_u_a = c4_nc + 1;
      c4_nc = c4_u_a;
      c4_c_data[c4_nc] = c4_ak;
      c4_x_a = c4_nia + 1;
      c4_nia = c4_x_a;
      c4_ia_data[c4_nia] = c4_iafirst;
      c4_bb_a = c4_b_ialast + 1;
      c4_ialast = c4_bb_a;
      c4_iafirst = c4_ialast;
      c4_eb_a = c4_c_iblast + 1;
      c4_iblast = c4_eb_a;
      c4_ibfirst = c4_iblast;
    } else {
      c4_t_a = c4_ak;
      c4_h_b = c4_b_bk;
      c4_v_a = c4_t_a;
      c4_i_b = c4_h_b;
      c4_f_p = (c4_v_a < c4_i_b);
      if (c4_f_p) {
        c4_ab_a = c4_nc + 1;
        c4_nc = c4_ab_a;
        c4_db_a = c4_nia + 1;
        c4_nia = c4_db_a;
        c4_c_data[c4_nc] = c4_ak;
        c4_ia_data[c4_nia] = c4_iafirst;
        c4_gb_a = c4_b_ialast + 1;
        c4_ialast = c4_gb_a;
        c4_iafirst = c4_ialast;
      } else {
        c4_y_a = c4_nc + 1;
        c4_nc = c4_y_a;
        c4_cb_a = c4_nib + 1;
        c4_nib = c4_cb_a;
        c4_c_data[c4_nc] = c4_b_bk;
        c4_ib_data[c4_nib - 1] = c4_ibfirst;
        c4_fb_a = c4_c_iblast + 1;
        c4_iblast = c4_fb_a;
        c4_ibfirst = c4_iblast;
      }
    }
  }

  while (c4_ialast <= c4_na) {
    c4_b_k = c4_ialast;
    c4_c_ialast = c4_b_k;
    c4_b_nx = c4_a_size[0];
    c4_b_ak = c4_a_data[c4_c_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_ialast < c4_b_nx)) {
      c4_d_a = c4_c_ialast + 1;
      c4_b_c = c4_d_a - 1;
      c4_b_xkplus = c4_a_data[c4_b_c];
      c4_i_a = c4_b_xkplus;
      c4_d_b = c4_b_ak;
      c4_b_p = (c4_i_a == c4_d_b);
      if (c4_b_p) {
        c4_o_a = c4_c_ialast + 1;
        c4_c_ialast = c4_o_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_c_a = c4_nc + 1;
    c4_nc = c4_c_a;
    c4_h_a = c4_nia + 1;
    c4_nia = c4_h_a;
    c4_c_data[c4_nc] = c4_b_ak;
    c4_ia_data[c4_nia] = c4_iafirst;
    c4_m_a = c4_c_ialast + 1;
    c4_ialast = c4_m_a;
    c4_iafirst = c4_ialast;
  }

  while (c4_iblast <= c4_nb) {
    c4_c_k = c4_iblast;
    c4_b_iblast = c4_c_k;
    c4_c_nx = c4_b_size[0];
    c4_bk = c4_b_data[c4_b_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_iblast < c4_c_nx)) {
      c4_g_a = c4_b_iblast + 1;
      c4_c_c = c4_g_a - 1;
      c4_c_xkplus = c4_b_data[c4_c_c];
      c4_k_a = c4_c_xkplus;
      c4_e_b = c4_bk;
      c4_c_p = (c4_k_a == c4_e_b);
      if (c4_c_p) {
        c4_r_a = c4_b_iblast + 1;
        c4_b_iblast = c4_r_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_f_a = c4_nc + 1;
    c4_nc = c4_f_a;
    c4_j_a = c4_nib + 1;
    c4_nib = c4_j_a;
    c4_c_data[c4_nc] = c4_bk;
    c4_ib_data[c4_nib - 1] = c4_ibfirst;
    c4_q_a = c4_b_iblast + 1;
    c4_iblast = c4_q_a;
    c4_ibfirst = c4_iblast;
  }

  if (c4_na > 0) {
    if (c4_nia + 1 > c4_na) {
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c4_g_y = NULL;
      sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_g_y)));
    }

    c4_b_b = (c4_nia + 1 < 1);
    if (c4_b_b) {
      c4_i = 0;
    } else {
      c4_i = c4_nia + 1;
    }

    c4_ia_size[0] = c4_i;
  }

  if (c4_nb > 0) {
    if (c4_nib > c4_nb) {
      c4_f_y = NULL;
      sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c4_i_y = NULL;
      sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_f_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_i_y)));
    }

    c4_b1 = (c4_nib < 1);
    if (c4_b1) {
      c4_i1 = 0;
    } else {
      c4_i1 = c4_nib;
    }

    c4_ib_size[0] = c4_i1;
  }

  if (c4_ncmax > 0) {
    if (c4_nc + 1 > c4_ncmax) {
      c4_h_y = NULL;
      sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c4_j_y = NULL;
      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_j_y)));
    }

    c4_b2 = (c4_nc + 1 < 1);
    if (c4_b2) {
      c4_i2 = 0;
    } else {
      c4_i2 = c4_nc + 1;
    }

    c4_c_size[0] = c4_i2;
  }
}

static boolean_T c4_issorted(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1])
{
  real_T c4_d;
  real_T c4_d1;
  int32_T c4_subs[2];
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_dim;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_c_dim;
  int32_T c4_c_k;
  int32_T c4_d_dim;
  int32_T c4_dim;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_nx;
  int32_T c4_varargin_1;
  int32_T c4_x1;
  int32_T c4_x2;
  boolean_T c4_c_b;
  boolean_T c4_exitg1;
  boolean_T c4_exitg2;
  boolean_T c4_y;
  (void)chartInstance;
  c4_y = true;
  c4_dim = 2;
  if (c4_x_size[0] != 1) {
    c4_dim = 1;
  }

  if (c4_dim <= 1) {
    c4_d = (real_T)c4_x_size[0];
  } else {
    c4_d = 1.0;
  }

  c4_nx = (int32_T)c4_d;
  if ((c4_x_size[0] == 0) || (c4_nx == 1)) {
  } else {
    c4_b_dim = c4_dim;
    c4_y = true;
    if (c4_b_dim == 2) {
      c4_n = 0;
    } else {
      c4_n = 1;
    }

    c4_i = (uint8_T)c4_n - 1;
    c4_k = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k <= c4_i)) {
      c4_c_dim = c4_b_dim;
      c4_y = true;
      if (c4_c_dim == 1) {
        c4_d1 = (real_T)c4_x_size[0];
        c4_b_n = (int32_T)c4_d1 - 1;
      } else {
        c4_b_n = c4_x_size[0];
      }

      c4_i1 = (uint8_T)c4_b_n - 1;
      c4_b_k = 1;
      c4_exitg2 = false;
      while ((!c4_exitg2) && (c4_b_k - 1 <= c4_i1)) {
        c4_c_k = c4_b_k;
        c4_d_dim = c4_c_dim - 1;
        c4_varargin_1 = c4_c_k;
        c4_x1 = c4_x_data[c4_varargin_1 - 1];
        c4_subs[0] = c4_varargin_1;
        c4_subs[1] = 1;
        c4_subs[c4_d_dim]++;
        c4_x2 = c4_x_data[c4_subs[0] - 1];
        c4_subs[0] = c4_x1;
        c4_subs[1] = c4_x2;
        c4_a = c4_subs[0];
        c4_b = c4_subs[1];
        c4_b_a = c4_a;
        c4_b_b = c4_b;
        c4_c_b = (c4_b_a <= c4_b_b);
        c4_y = c4_c_b;
        if (!c4_y) {
          c4_exitg2 = true;
        } else {
          c4_b_k++;
        }
      }

      if (!c4_y) {
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  return c4_y;
}

static void c4_b_introsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1], int32_T c4_xend,
  int32_T c4_b_x_data[], int32_T c4_b_x_size[1])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_b_x_size[0] = c4_x_size[0];
  c4_loop_ub = c4_x_size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_x_data[c4_i] = c4_x_data[c4_i];
  }

  c4_d_introsort(chartInstance, c4_sp, c4_b_x_data, c4_xend);
}

static void c4_b_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x_data[], int32_T c4_x_size[1], int32_T c4_xend, int32_T
  c4_b_x_data[], int32_T c4_b_x_size[1])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_b_x_size[0] = c4_x_size[0];
  c4_loop_ub = c4_x_size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_x_data[c4_i] = c4_x_data[c4_i];
  }

  c4_e_insertionsort(chartInstance, c4_b_x_data, c4_xend);
}

static void c4_c_insertionsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1], int32_T
  c4_xstart, int32_T c4_xend, int32_T c4_b_x_data[], int32_T c4_b_x_size[1])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_b_x_size[0] = c4_x_size[0];
  c4_loop_ub = c4_x_size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_x_data[c4_i] = c4_x_data[c4_i];
  }

  c4_f_insertionsort(chartInstance, c4_sp, c4_b_x_data, c4_xstart, c4_xend);
}

static void c4_heapsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1], int32_T c4_xstart, int32_T c4_xend, int32_T
  c4_b_x_data[], int32_T c4_b_x_size[1])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_b_x_size[0] = c4_x_size[0];
  c4_loop_ub = c4_x_size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_x_data[c4_i] = c4_x_data[c4_i];
  }

  c4_b_heapsort(chartInstance, c4_b_x_data, c4_xstart, c4_xend);
}

static void c4_heapify(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_x_size[1], int32_T c4_idx, int32_T c4_xstart, int32_T
  c4_xend, int32_T c4_b_x_data[], int32_T c4_b_x_size[1])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_b_x_size[0] = c4_x_size[0];
  c4_loop_ub = c4_x_size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_x_data[c4_i] = c4_x_data[c4_i];
  }

  c4_b_heapify(chartInstance, c4_b_x_data, c4_idx, c4_xstart, c4_xend);
}

static void c4_indexShapeCheck(SFc4_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_b_indexShapeCheck(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2])
{
  static char_T c4_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  boolean_T c4_nonSingletonDimFound;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_nonSingletonDimFound = false;
    if (c4_indexSize[1] != 1) {
      c4_nonSingletonDimFound = true;
    }

    c4_b_b = c4_nonSingletonDimFound;
    if (c4_b_b) {
      c4_c = true;
    } else {
      c4_c = false;
    }
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_wb_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_l_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

const mxArray *sf_c4_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_emlrt_marshallIn(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier, real_T c4_y[128])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_nullptr);
}

static void c4_b_emlrt_marshallIn(SFc4_untitledInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[128])
{
  real_T c4_dv[128];
  int32_T c4_i;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv, 1, 0, 0U, 1, 0U, 2, 128, 1);
  for (c4_i = 0; c4_i < 128; c4_i++) {
    c4_y[c4_i] = c4_dv[c4_i];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_slStringInitializeDynamicBuffers(SFc4_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c4_feval(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_b_feval(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_c_introsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x[4], c4_anonymous_function c4_cmp)
{
  c4_d_insertionsort(chartInstance, c4_x, c4_cmp);
}

static void c4_d_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x[4], c4_anonymous_function c4_cmp)
{
  c4_cell_11 c4_workspace;
  int32_T c4_a[4];
  int32_T c4_b[4];
  int32_T c4_ai;
  int32_T c4_aj;
  int32_T c4_b_i;
  int32_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_idx;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_varargin_1;
  int32_T c4_varargin_2;
  int32_T c4_xc;
  boolean_T c4_exitg1;
  boolean_T c4_varargout_1;
  (void)chartInstance;
  for (c4_k = 0; c4_k < 3; c4_k++) {
    c4_xc = c4_x[c4_k + 1];
    c4_idx = c4_k;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_idx + 1 >= 1)) {
      c4_varargin_1 = c4_xc;
      c4_varargin_2 = c4_x[c4_idx];
      for (c4_i = 0; c4_i < 4; c4_i++) {
        c4_workspace.f1[c4_i] = c4_cmp.workspace.a[c4_i];
      }

      for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
        c4_workspace.f2[c4_i1] = c4_cmp.workspace.b[c4_i1];
      }

      for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
        c4_a[c4_i2] = c4_workspace.f1[c4_i2];
      }

      for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
        c4_b[c4_i3] = c4_workspace.f2[c4_i3];
      }

      c4_b_i = c4_varargin_1;
      c4_j = c4_varargin_2;
      c4_c_i = c4_b_i - 1;
      c4_b_j = c4_j - 1;
      c4_ai = c4_a[c4_c_i];
      c4_aj = c4_a[c4_b_j];
      if (c4_ai < c4_aj) {
        c4_varargout_1 = true;
      } else if (c4_ai == c4_aj) {
        c4_varargout_1 = (c4_b[c4_c_i] < c4_b[c4_b_j]);
      } else {
        c4_varargout_1 = false;
      }

      if (c4_varargout_1) {
        c4_x[c4_idx + 1] = c4_x[c4_idx];
        c4_idx--;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_x[c4_idx + 1] = c4_xc;
  }
}

static int32_T c4_b_pivot(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_v[128], int32_T *c4_ip, int32_T c4_ia, int32_T
  c4_ib)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_vk;
  real_T c4_vref;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_i;
  int32_T c4_k;
  int32_T c4_reps;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_vref = c4_v[*c4_ip - 1];
  c4_v[*c4_ip - 1] = c4_v[c4_ib - 1];
  c4_v[c4_ib - 1] = c4_vref;
  *c4_ip = c4_ia;
  c4_reps = 0;
  c4_i = c4_ib - 1;
  c4_st.site = &c4_x_emlrtRSI;
  c4_a = c4_ia;
  c4_b = c4_i;
  c4_b_a = c4_a;
  c4_b_b = c4_b;
  if (c4_b_a > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_y_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_k = c4_ia; c4_k <= c4_i; c4_k++) {
    c4_vk = c4_v[c4_k - 1];
    if (c4_vk == c4_vref) {
      c4_v[c4_k - 1] = c4_v[*c4_ip - 1];
      c4_v[*c4_ip - 1] = c4_vk;
      c4_reps++;
      (*c4_ip)++;
    } else {
      c4_c_a = c4_vk;
      c4_c_b = c4_vref;
      c4_d_a = c4_c_a;
      c4_d_b = c4_c_b;
      c4_p = (c4_d_a < c4_d_b);
      if (c4_p) {
        c4_v[c4_k - 1] = c4_v[*c4_ip - 1];
        c4_v[*c4_ip - 1] = c4_vk;
        (*c4_ip)++;
      }
    }
  }

  c4_v[c4_ib - 1] = c4_v[*c4_ip - 1];
  c4_v[*c4_ip - 1] = c4_vref;
  return c4_reps;
}

static void c4_b_medmed(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
  [128], int32_T c4_nv, int32_T c4_ia)
{
  real_T c4_tmp;
  int32_T c4_a;
  int32_T c4_b_k;
  int32_T c4_destidx;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_im;
  int32_T c4_k;
  int32_T c4_ngroupsof5;
  int32_T c4_nlast;
  while (c4_nv > 1) {
    c4_a = c4_nv;
    c4_ngroupsof5 = c4_div_nzp_s32(chartInstance, c4_a, 5, 0, 0U, 0, 0);
    c4_nlast = c4_nv - c4_ngroupsof5 * 5;
    c4_nv = c4_ngroupsof5;
    c4_i = (uint8_T)c4_ngroupsof5;
    for (c4_k = 0; c4_k < c4_i; c4_k++) {
      c4_b_k = c4_k;
      c4_i1 = c4_ia + c4_b_k * 5;
      c4_i2 = c4_i1;
      c4_im = c4_thirdOfFive(chartInstance, c4_v, c4_i1, c4_i2 + 4) - 1;
      c4_destidx = (c4_ia + c4_b_k) - 1;
      c4_tmp = c4_v[c4_destidx];
      c4_v[c4_destidx] = c4_v[c4_im];
      c4_v[c4_im] = c4_tmp;
    }

    if (c4_nlast > 0) {
      c4_i1 = c4_ia + c4_ngroupsof5 * 5;
      c4_i2 = c4_i1 + c4_nlast;
      c4_im = c4_thirdOfFive(chartInstance, c4_v, c4_i1, c4_i2 - 1) - 1;
      c4_destidx = (c4_ia + c4_ngroupsof5) - 1;
      c4_tmp = c4_v[c4_destidx];
      c4_v[c4_destidx] = c4_v[c4_im];
      c4_v[c4_im] = c4_tmp;
      c4_nv = c4_ngroupsof5 + 1;
    }
  }
}

static void c4_b_med3(SFc4_untitledInstanceStruct *chartInstance, real_T c4_v
                      [128], int32_T c4_nv, int32_T c4_ia, int32_T c4_ib)
{
  real_T c4_b;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_j_a;
  real_T c4_j_b;
  real_T c4_k_a;
  real_T c4_tmp;
  real_T c4_v1;
  real_T c4_v2;
  real_T c4_v3;
  int32_T c4_a;
  int32_T c4_c;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_ic;
  int32_T c4_jc;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_p;
  if (c4_nv >= 3) {
    c4_a = c4_nv;
    c4_c = c4_div_nzp_s32(chartInstance, c4_a - 1, 2, 0, 0U, 0, 0);
    c4_ic = c4_ia + c4_c;
    c4_i1 = c4_ia;
    c4_v1 = c4_v[c4_ia - 1];
    c4_i2 = c4_ic;
    c4_v2 = c4_v[c4_ic - 1];
    c4_i3 = c4_ib;
    c4_v3 = c4_v[c4_ib - 1];
    c4_b_a = c4_v1;
    c4_b = c4_v2;
    c4_c_a = c4_b_a;
    c4_b_b = c4_b;
    c4_p = (c4_c_a < c4_b_b);
    if (c4_p) {
      c4_e_a = c4_v2;
      c4_d_b = c4_v3;
      c4_g_a = c4_e_a;
      c4_f_b = c4_d_b;
      c4_c_p = (c4_g_a < c4_f_b);
      if (c4_c_p) {
        c4_jc = c4_i2;
      } else {
        c4_i_a = c4_v1;
        c4_h_b = c4_v3;
        c4_k_a = c4_i_a;
        c4_j_b = c4_h_b;
        c4_e_p = (c4_k_a < c4_j_b);
        if (c4_e_p) {
          c4_jc = c4_i3;
        } else {
          c4_jc = c4_i1;
        }
      }
    } else {
      c4_d_a = c4_v1;
      c4_c_b = c4_v3;
      c4_f_a = c4_d_a;
      c4_e_b = c4_c_b;
      c4_b_p = (c4_f_a < c4_e_b);
      if (c4_b_p) {
        c4_jc = c4_i1;
      } else {
        c4_h_a = c4_v2;
        c4_g_b = c4_v3;
        c4_j_a = c4_h_a;
        c4_i_b = c4_g_b;
        c4_d_p = (c4_j_a < c4_i_b);
        if (c4_d_p) {
          c4_jc = c4_i3;
        } else {
          c4_jc = c4_i2;
        }
      }
    }

    if (c4_jc > c4_ia) {
      c4_tmp = c4_v[c4_ia - 1];
      c4_v[c4_ia - 1] = c4_v[c4_jc - 1];
      c4_v[c4_jc - 1] = c4_tmp;
    }
  }
}

static void c4_d_introsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_xend)
{
  static char_T c4_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c4_cv2[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c4_cv3[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c4_cv1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'o', 'p', 'E', 'm', 'p',
    't', 'y' };

  c4_coder_internal_stack c4_b_st;
  c4_sBaHy6MF1FZJsDHxMqvBaiH c4_b_x;
  c4_sBaHy6MF1FZJsDHxMqvBaiH c4_c_x;
  c4_sBaHy6MF1FZJsDHxMqvBaiH c4_frame;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  real_T c4_d;
  real_T c4_d1;
  int32_T c4_iv[2];
  int32_T c4_MAXDEPTH;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_n;
  int32_T c4_b_nd;
  int32_T c4_b_p;
  int32_T c4_b_xend;
  int32_T c4_b_xstart;
  int32_T c4_c;
  int32_T c4_c_n;
  int32_T c4_c_nd;
  int32_T c4_c_pivot;
  int32_T c4_d_n;
  int32_T c4_depth;
  int32_T c4_e_n;
  int32_T c4_exitg2;
  int32_T c4_exitg3;
  int32_T c4_i;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_nd;
  int32_T c4_p;
  int32_T c4_pmax;
  int32_T c4_pmin;
  int32_T c4_pow2p;
  int32_T c4_t;
  int32_T c4_x;
  int32_T c4_xmid;
  int32_T c4_xstart;
  int32_T c4_y;
  boolean_T c4_exitg1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  if (c4_xend <= 1) {
  } else if (c4_xend <= 32) {
    c4_e_insertionsort(chartInstance, c4_x_data, c4_xend);
  } else {
    c4_n = c4_xend;
    c4_x = c4_n;
    c4_p = c4_x;
    c4_b_n = c4_p;
    c4_c_n = c4_b_n;
    c4_pmax = 31;
    c4_pmin = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_pmax - c4_pmin > 1)) {
      c4_p = (c4_pmin + c4_pmax) >> 1;
      c4_pow2p = 1 << c4_p;
      if (c4_pow2p == c4_c_n) {
        c4_pmax = c4_p;
        c4_exitg1 = true;
      } else if (c4_pow2p > c4_c_n) {
        c4_pmax = c4_p;
      } else {
        c4_pmin = c4_p;
      }
    }

    c4_p = c4_pmax - 1;
    c4_b = c4_p;
    c4_MAXDEPTH = c4_b << 1;
    c4_frame.xstart = 1;
    c4_frame.xend = c4_xend;
    c4_frame.depth = 0;
    c4_b_b = c4_MAXDEPTH;
    c4_y = c4_b_b << 1;
    c4_st.site = &c4_ub_emlrtRSI;
    c4_d_n = c4_y;
    c4_d = (real_T)c4_d_n;
    if (!(c4_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c4_d, &c4_f_emlrtDCI, &c4_st);
    }

    c4_iv[0] = (int32_T)muDoubleScalarFloor(c4_d);
    c4_d1 = 1.0;
    if (!(c4_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c4_d1, &c4_f_emlrtDCI, &c4_st);
    }

    c4_b_st.d.size[0] = c4_iv[0];
    c4_st.site = &c4_pb_emlrtRSI;
    c4_nd = c4_b_st.d.size[0];
    if (c4_nd <= 0) {
      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      c4_c_y = NULL;
      sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      sf_mex_call(&c4_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                  sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
    }

    c4_b_st.d.data[0] = c4_frame;
    c4_b_st.n = 1;
    do {
      c4_exitg2 = 0;
      c4_e_n = c4_b_st.n;
      if (c4_e_n > 0) {
        c4_st.site = &c4_qb_emlrtRSI;
        if (c4_b_st.n <= 0) {
          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          c4_e_y = NULL;
          sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          sf_mex_call(&c4_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                      sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
        }

        c4_frame = c4_b_st.d.data[c4_b_st.n - 1];
        c4_b_st.n--;
        c4_xstart = c4_frame.xstart;
        c4_xend = c4_frame.xend;
        c4_depth = c4_frame.depth + 1;
        if ((c4_xend - c4_xstart) + 1 <= 32) {
          c4_st.site = &c4_rb_emlrtRSI;
          c4_f_insertionsort(chartInstance, &c4_st, c4_x_data, c4_xstart,
                             c4_xend);
        } else if (c4_depth - 1 == c4_MAXDEPTH) {
          c4_b_heapsort(chartInstance, c4_x_data, c4_xstart, c4_xend);
        } else {
          c4_b_xstart = c4_xstart - 1;
          c4_b_xend = c4_xend - 1;
          c4_a = c4_b_xend - c4_b_xstart;
          c4_c = c4_div_nzp_s32(chartInstance, c4_a, 2, 0, 0U, 0, 0);
          c4_xmid = c4_b_xstart + c4_c;
          if (c4_x_data[c4_xmid] < c4_x_data[c4_b_xstart]) {
            c4_t = c4_x_data[c4_b_xstart];
            c4_x_data[c4_b_xstart] = c4_x_data[c4_xmid];
            c4_x_data[c4_xmid] = c4_t;
          }

          if (c4_x_data[c4_b_xend] < c4_x_data[c4_b_xstart]) {
            c4_t = c4_x_data[c4_b_xstart];
            c4_x_data[c4_b_xstart] = c4_x_data[c4_b_xend];
            c4_x_data[c4_b_xend] = c4_t;
          }

          if (c4_x_data[c4_b_xend] < c4_x_data[c4_xmid]) {
            c4_t = c4_x_data[c4_xmid];
            c4_x_data[c4_xmid] = c4_x_data[c4_b_xend];
            c4_x_data[c4_b_xend] = c4_t;
          }

          c4_c_pivot = c4_x_data[c4_xmid];
          c4_x_data[c4_xmid] = c4_x_data[c4_b_xend - 1];
          c4_x_data[c4_b_xend - 1] = c4_c_pivot;
          c4_i = c4_b_xstart;
          c4_j = c4_b_xend - 1;
          do {
            c4_exitg3 = 0;
            for (c4_i++; c4_x_data[c4_i] < c4_c_pivot; c4_i++) {
            }

            for (c4_j--; c4_c_pivot < c4_x_data[c4_j]; c4_j--) {
            }

            if (c4_i + 1 >= c4_j + 1) {
              c4_exitg3 = 1;
            } else {
              c4_t = c4_x_data[c4_i];
              c4_x_data[c4_i] = c4_x_data[c4_j];
              c4_x_data[c4_j] = c4_t;
            }
          } while (c4_exitg3 == 0);

          c4_b_p = c4_i + 1;
          c4_x_data[c4_b_xend - 1] = c4_x_data[c4_i];
          c4_x_data[c4_i] = c4_c_pivot;
          if (c4_b_p + 1 < c4_xend) {
            c4_b_x.xstart = c4_b_p + 1;
            c4_b_x.xend = c4_xend;
            c4_b_x.depth = c4_depth;
            c4_st.site = &c4_sb_emlrtRSI;
            c4_b_nd = c4_b_st.d.size[0];
            if (c4_b_st.n >= c4_b_nd) {
              c4_f_y = NULL;
              sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c4_h_y = NULL;
              sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c4_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_f_y,
                          14, sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c4_st, NULL, "message", 1U, 1U, 14, c4_h_y)));
            }

            c4_b_st.d.data[c4_b_st.n] = c4_b_x;
            c4_b_st.n++;
          }

          if (c4_xstart < c4_b_p) {
            c4_c_x.xstart = c4_xstart;
            c4_c_x.xend = c4_b_p;
            c4_c_x.depth = c4_depth;
            c4_st.site = &c4_tb_emlrtRSI;
            c4_c_nd = c4_b_st.d.size[0];
            if (c4_b_st.n >= c4_c_nd) {
              c4_g_y = NULL;
              sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c4_i_y = NULL;
              sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c4_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_g_y,
                          14, sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c4_st, NULL, "message", 1U, 1U, 14, c4_i_y)));
            }

            c4_b_st.d.data[c4_b_st.n] = c4_c_x;
            c4_b_st.n++;
          }
        }
      } else {
        c4_exitg2 = 1;
      }
    } while (c4_exitg2 == 0);
  }
}

static void c4_e_insertionsort(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_x_data[], int32_T c4_xend)
{
  int32_T c4_idx;
  int32_T c4_k;
  int32_T c4_xc;
  (void)chartInstance;
  for (c4_k = 2; c4_k <= c4_xend; c4_k++) {
    c4_xc = c4_x_data[c4_k - 1];
    c4_idx = c4_k - 1;
    while ((c4_idx >= 1) && (c4_xc < c4_x_data[c4_idx - 1])) {
      c4_x_data[c4_idx] = c4_x_data[c4_idx - 1];
      c4_idx--;
    }

    c4_x_data[c4_idx] = c4_xc;
  }
}

static void c4_f_insertionsort(SFc4_untitledInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_xstart, int32_T c4_xend)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_i;
  int32_T c4_idx;
  int32_T c4_k;
  int32_T c4_xc;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_i = c4_xstart + 1;
  c4_st.site = &c4_vb_emlrtRSI;
  c4_a = c4_i;
  c4_b = c4_xend;
  c4_b_a = c4_a;
  c4_b_b = c4_b;
  if (c4_b_a > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_y_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_k = c4_i; c4_k <= c4_xend; c4_k++) {
    c4_xc = c4_x_data[c4_k - 1];
    c4_idx = c4_k - 1;
    while ((c4_idx >= c4_xstart) && (c4_xc < c4_x_data[c4_idx - 1])) {
      c4_x_data[c4_idx] = c4_x_data[c4_idx - 1];
      c4_idx--;
    }

    c4_x_data[c4_idx] = c4_xc;
  }
}

static void c4_b_heapsort(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_xstart, int32_T c4_xend)
{
  int32_T c4_b_n;
  int32_T c4_b_xend;
  int32_T c4_b_xstart;
  int32_T c4_i;
  int32_T c4_idx;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_t;
  c4_n = c4_xend - c4_xstart;
  c4_b_xstart = c4_xstart;
  c4_b_xend = c4_xend;
  c4_b_n = c4_n + 1;
  for (c4_idx = c4_b_n; c4_idx >= 1; c4_idx--) {
    c4_b_heapify(chartInstance, c4_x_data, c4_idx, c4_b_xstart, c4_b_xend);
  }

  c4_i = c4_n;
  for (c4_k = 0; c4_k < c4_i; c4_k++) {
    c4_t = c4_x_data[c4_xend - 1];
    c4_x_data[c4_xend - 1] = c4_x_data[c4_xstart - 1];
    c4_x_data[c4_xstart - 1] = c4_t;
    c4_xend--;
    c4_b_heapify(chartInstance, c4_x_data, 1, c4_xstart, c4_xend);
  }
}

static void c4_b_heapify(SFc4_untitledInstanceStruct *chartInstance, int32_T
  c4_x_data[], int32_T c4_idx, int32_T c4_xstart, int32_T c4_xend)
{
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_y;
  int32_T c4_cmpIdx;
  int32_T c4_extremum;
  int32_T c4_extremumIdx;
  int32_T c4_leftIdx;
  int32_T c4_rightIdx;
  int32_T c4_xcmp;
  int32_T c4_xoff;
  int32_T c4_xr;
  int32_T c4_y;
  boolean_T c4_changed;
  (void)chartInstance;
  c4_changed = true;
  c4_xoff = c4_xstart - 1;
  c4_extremumIdx = (c4_idx + c4_xoff) - 1;
  c4_b = c4_idx;
  c4_y = c4_b << 1;
  c4_leftIdx = c4_y + c4_xoff;
  while (c4_changed && (c4_leftIdx < c4_xend)) {
    c4_changed = false;
    c4_rightIdx = c4_leftIdx;
    c4_extremum = c4_x_data[c4_extremumIdx];
    c4_cmpIdx = c4_leftIdx;
    c4_xcmp = c4_x_data[c4_leftIdx - 1];
    c4_xr = c4_x_data[c4_rightIdx];
    if (c4_xcmp < c4_xr) {
      c4_cmpIdx = c4_leftIdx + 1;
      c4_xcmp = c4_xr;
    }

    if (c4_extremum < c4_xcmp) {
      c4_x_data[c4_extremumIdx] = c4_xcmp;
      c4_x_data[c4_cmpIdx - 1] = c4_extremum;
      c4_extremumIdx = c4_cmpIdx - 1;
      c4_b_b = c4_cmpIdx - c4_xoff;
      c4_b_y = c4_b_b << 1;
      c4_leftIdx = c4_b_y + c4_xoff;
      c4_changed = true;
    }
  }

  if (c4_changed && (c4_leftIdx <= c4_xend)) {
    c4_extremum = c4_x_data[c4_extremumIdx];
    c4_xcmp = c4_x_data[c4_leftIdx - 1];
    if (c4_extremum < c4_xcmp) {
      c4_x_data[c4_extremumIdx] = c4_xcmp;
      c4_x_data[c4_leftIdx - 1] = c4_extremum;
    }
  }
}

static void c4_array_real_T_SetSize(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray, const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  real_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_int32_T_SetSize(SFc4_untitledInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray, const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  int32_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_sparse_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_sparse *c4_pStruct)
{
  c4_array_real_T_Constructor(chartInstance, &c4_pStruct->d);
  c4_array_int32_T_Constructor(chartInstance, &c4_pStruct->colidx);
  c4_array_int32_T_Constructor(chartInstance, &c4_pStruct->rowidx);
}

static void c4_array_real_T_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_int32_T_Constructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (int32_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_real_T_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_sparse_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_sparse *c4_pStruct)
{
  c4_array_real_T_Destructor(chartInstance, &c4_pStruct->d);
  c4_array_int32_T_Destructor(chartInstance, &c4_pStruct->colidx);
  c4_array_int32_T_Destructor(chartInstance, &c4_pStruct->rowidx);
}

static void c4_array_int32_T_Destructor(SFc4_untitledInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static int32_T c4_div_nzp_s32(SFc4_untitledInstanceStruct *chartInstance,
  int32_T c4_numerator, int32_T c4_denominator, int32_T c4_EMLOvCount_src_loc,
  uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  int32_T c4_quotient;
  uint32_T c4_absDenominator;
  uint32_T c4_absNumerator;
  uint32_T c4_tempAbsQuotient;
  boolean_T c4_quotientNeedsNegation;
  (void)chartInstance;
  (void)c4_EMLOvCount_src_loc;
  (void)c4_ssid_src_loc;
  (void)c4_offset_src_loc;
  (void)c4_length_src_loc;
  if (c4_numerator < 0) {
    c4_absNumerator = ~(uint32_T)c4_numerator + 1U;
  } else {
    c4_absNumerator = (uint32_T)c4_numerator;
  }

  if (c4_denominator < 0) {
    c4_absDenominator = ~(uint32_T)c4_denominator + 1U;
  } else {
    c4_absDenominator = (uint32_T)c4_denominator;
  }

  c4_quotientNeedsNegation = ((c4_numerator < 0) != (c4_denominator < 0));
  c4_tempAbsQuotient = c4_absNumerator / c4_absDenominator;
  if (c4_quotientNeedsNegation) {
    c4_quotient = -(int32_T)c4_tempAbsQuotient;
  } else {
    c4_quotient = (int32_T)c4_tempAbsQuotient;
  }

  return c4_quotient;
}

static void init_dsm_address_info(SFc4_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_untitledInstanceStruct *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_a3_in = (real_T (*)[128])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_a3_smoothed = (real_T (*)[128])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2819391761U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1061499395U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4118289508U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1649774113U);
}

mxArray *sf_c4_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.CXSparseAPI"));
  return(mxcell3p);
}

mxArray *sf_c4_untitled_jit_fallback_info(void)
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

mxArray *sf_c4_untitled_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOl3QNLPgkU/N5J+ASg/0Ti+ODc/vyQjNYUBFk4gAA"
    "BVORDF"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "speT45VBbCExN9y26CVluYC";
}

static void sf_opaque_initialize_c4_untitled(void *chartInstanceVar)
{
  initialize_params_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
  initialize_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_untitled(void *chartInstanceVar)
{
  enable_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_untitled(void *chartInstanceVar)
{
  disable_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_untitled(void *chartInstanceVar)
{
  sf_gateway_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_untitled(SimStruct* S)
{
  return get_sim_state_c4_untitled((SFc4_untitledInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_untitled(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_untitled((SFc4_untitledInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_untitled(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_untitled((SFc4_untitledInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_untitled(void *chartInstanceVar)
{
  mdl_start_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_untitledInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_untitled(void *chartInstanceVar)
{
  mdl_terminate_c4_untitled((SFc4_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_untitled(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_untitled((SFc4_untitledInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_untitled_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWE2P20QYnmyXFeWjFAmpPSCBxIUTqthSgUC0u45TIna7Ec4ugks1sd/Eox3PuPORTTjzOyr",
    "1L3Dmzl+okDjwDzhy5B3HyZpsyHocqdtiyesd28887zzzfjmk1T0keNzA85tbhOzg9XU8t8jseK",
    "0ctyrn7P42+aoc994gJE6pMl0xlMT/iGUCIxCRHQ7ZxBMrbNajima6Aa+gGXwHWnJrmBR+xjMxB",
    "AUixglyqYwXr2aZ5UycdqyIHbP+PmVxGqXS8mQfJ6TJkeDT/+LNrekhY5spiE0HIDGpknaUdjgd",
    "rVdBmbMghfhU28xbKw0msrlbqj603LCcQziBuCu0oaiCvmS9kaEGAjPx9hCmozlaZjlnVNTXOqU",
    "6ghy9w8BxnuDfI2tQvZq8yDdgghqpGOVhxgPn4TWxPY52HqJbc2+dTWbaMLCjERMjp66yGQhcP/",
    "pJDa2GgRyDoiM4Ep4x6FYXTooNXvhl/RjsOrdsFIM2m+2KboQteMMxKqQb8nZiEVDOtR+2L/MDG",
    "AMv+NvU0AbYGb8HWGuW9OUJVS4KPCPJCvbEQokNpEhY/R0eL6GKhPsIk2cNOMucS0GCMi9MX0x0",
    "mU9abWQWYBi1Dw5q8l3EdoUBNaQx1M59ijINaHDhV568CdN0wB0aVTLFKmvPAKIxlOihFe0zqU5",
    "RY98ke66ViwQ/NCQjaIOBImGE6N0nlNuaNmcaM5xzj2ONGcuPF7EufhqBYxqnkLh6wjgcgnYT6N",
    "r5GevIHq52zMy0DTpWLK8bSVZDgoXEqdSf5nAsToU8Ex0ls6jsCNb4FQBmDaoEloV9LEtq2kHj6",
    "1mt4EnfeVaT9iyjhtOB842HILCyuLW6SkhjjKpQYOuGBm2CjdhPWNqFZtpgOzUNixhIin70dsuv",
    "H323HO8uYqmr+wp3imIZFtgp7Q2KZg/6LIPiRkSxp5gNy8Px3iHnvNe31vNu4X+thjiyIe5BBbe",
    "9Qp83K7ib5Ti++9gKTC5O41X8b9XQuQ6OXMCd6zu/flzBt1bwksp1k32p6vT2Es/2Em6n1Oqd8G",
    "nn94/+/OXXT/549hv78udN+J97+vGNcvz+vC9bVK7xheRefLdd4ge3lvzAjXUO/bufnewPgnDy6",
    "Ivpp/eCE25/CGb74mnv/P6HeBpMbEWeVHE3Kb+x3JjaWe/v5v+8Yu/OJfNfr/gTIX/d3wz/3oOm",
    "cUN3H+tMSpNW4uZVyRdXlZ+u0s46eaz1gnHkBeM2XZ9vfn7V37+zJi+QpfdvvsTrWJeffOr0y7a",
    "u58SvLn1Qjr9efDsHKePJiu69fIwN9nDV0/+Jf//tqd+8bwidfuWPfz/u7gnKp9iuzz6Hyts95X",
    "53WjxSQPXqb6KrqEN14tu9fe1f8X2NPNz/tnEd+wfSTvyV",
    ""
  };

  static char newstr [1397] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_untitled(SimStruct *S)
{
  const char* newstr = sf_c4_untitled_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1184777487U));
  ssSetChecksum1(S,(3001099226U));
  ssSetChecksum2(S,(2715627196U));
  ssSetChecksum3(S,(2218486215U));
}

static void mdlRTW_c4_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_untitled(SimStruct *S)
{
  SFc4_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc4_untitledInstanceStruct *)utMalloc(sizeof
    (SFc4_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_untitledInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_untitled;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_untitled;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_untitled;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_untitled;
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

  mdl_setup_runtime_resources_c4_untitled(chartInstance);
}

void c4_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
