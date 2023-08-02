#include "libavutil/intreadwrite.h"
#include "parser.h"

static int klv_parse(AVCodecParserContext* s1, AVCodecContext* avctx,
    const uint8_t** poutbuf, int* poutbuf_size,
    const uint8_t* buf, int buf_size)
{
    /* always return the full packet. this parser isn't doing any splitting or
       combining, only setting packet duration */
    *poutbuf = buf;
    *poutbuf_size = buf_size;
    return buf_size;
}


AVCodecParser ff_klv_parser = {
	.codec_ids = { AV_CODEC_ID_SMPTE_KLV},
	.parser_parse = klv_parse
};