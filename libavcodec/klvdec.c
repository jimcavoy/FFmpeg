#include "libavutil/frame.h"
#include "avcodec.h"
#include "codec_internal.h"

/**
 * @file
 * SMPTE 336M Key-Length-Value (KLV) metadata decoder
 */

static av_cold int decode_init(AVCodecContext *avctx)
{
    return 0;
}

static av_cold int decode_end(AVCodecContext *avctx)
{
    return 0;
}

static int decode_frame(AVCodecContext *avctx, void *data, int *got_frame,
    AVPacket *avpkt)
{
    AVFrame *frame = data;

    memcpy(frame->data[0], avpkt->data, avpkt->size);

    *got_frame = 1;
    return avpkt->size;
}

static void decode_flush(AVCodecContext *avctx)
{
    return 0;
}

const FFCodec ff_klv_decoder = {
    .p.name = "klv",
    .p.long_name = NULL_IF_CONFIG_SMALL("SMPTE 336M Key-Length-Value (KLV) metadata"),
    .p.type = AVMEDIA_TYPE_DATA,
    .p.id = AV_CODEC_ID_SMPTE_KLV,
    .init = decode_init,
    .close = decode_end,
    FF_CODEC_DECODE_CB(decode_frame),
    .flush = decode_flush
};