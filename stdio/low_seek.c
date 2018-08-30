/*******************************************************************************
 *
 * Copyright (C) 2014-2018 MIPS Tech, LLC
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

/**************************************************************************//**
@File         low_seek.c

@Title        Low-level IO seek function


@


@Platform     Any

@Synopsis     int low_seek (__smFILE *fp, int off, int dir);

@Description  Performs seek on speicifed file.

@DocVer       1.0 1st Release
******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <low/_stdio.h>

_fpos_t low_seek (__smFILE *fp, int off, int dir)
{
  _fpos_t ret;
  funcookie *fc = (funcookie*) fp->_cookie;
  
  if (fc != NULL)
      return fc->seekfn (fc->cookie, off, dir);
  else
    {
      ret = lseek (fp->_fileid, off, dir);
      fp->_offset = ret;
      fp->_flags |= __SOFF;
      return ret;
    }
}/* low_seek */

