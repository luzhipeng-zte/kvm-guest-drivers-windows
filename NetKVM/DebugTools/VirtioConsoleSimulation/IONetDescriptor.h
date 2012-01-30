/**********************************************************************
 * Copyright (c) 2008  Red Hat, Inc.
 *
 * File: IONetDescriptor.h
 *
 * This file contains common guest/host definition, related
 * to VirtIO network adapter
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
**********************************************************************/
#ifndef IONETDESCRIPTOR_H
#define IONETDESCRIPTOR_H

#pragma pack (push)
#pragma pack (1)
/* This is the first element of the scatter-gather list.  If you don't
 * specify GSO or CSUM features, you can simply ignore the header. */
typedef struct _tagvirtio_net_hdr
{
#define VIRTIO_NET_HDR_F_NEEDS_CSUM	1	// Use csum_start, csum_offset
	u8 flags;
#define VIRTIO_NET_HDR_GSO_NONE		0	// Not a GSO frame
#define VIRTIO_NET_HDR_GSO_TCPV4	1	// GSO frame, IPv4 TCP (TSO)
#define VIRTIO_NET_HDR_F_DATA_VALID 2	// Host checked checksum, no need to recheck
#define VIRTIO_NET_HDR_GSO_UDP		3	// GSO frame, IPv4 UDP (UFO)
#define VIRTIO_NET_HDR_GSO_TCPV6	4	// GSO frame, IPv6 TCP
#define VIRTIO_NET_HDR_GSO_ECN		0x80	// TCP has ECN set
	u8 gso_type;
	u16 hdr_len;						// Ethernet + IP + tcp/udp hdrs
	u16 gso_size;						// Bytes to append to gso_hdr_len per frame
	u16 csum_start;						// Position to start checksumming from
	u16 csum_offset;					// Offset after that to place checksum
}virtio_net_hdr_basic;

typedef struct _tagvirtio_net_hdr_ext
{
	virtio_net_hdr_basic BasicHeader;
	u16 nBuffers;
}virtio_net_hdr_ext;

#pragma pack (pop)

#endif
