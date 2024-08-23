// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Atcommands
 * Place the body of custom atcommands in this file.
 * Format:
 *	ACMD_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//ACMD_FUNC(newcommand)
//{
//	clif_displaymessage(fd, "It works!");
//	clif_specialeffect(&sd->bl, EF_HEARTCASTING, AREA);
//	return 0;
//}

/*==========================================
 * @debuff by Start's
 * reduces player damage / defense and flee by percentage
 *------------------------------------------*/
ACMD_FUNC(debuff)
{
	int value = 0;
	nullpo_retr(-1, sd);
	char temp[CHAT_SIZE_MAX];

	memset(temp, '\0', sizeof(temp));

	if (!message || !*message)
		return -1;

	value = atoi(message);

	sd->debuff = cap_value(value,0,100);

	StringBuf buf;
	StringBuf_Init(&buf);
	StringBuf_Printf(&buf, msg_txt(sd,1536), value); // Debuff: %d
	clif_displaymessage(fd, StringBuf_Value(&buf));
	StringBuf_Destroy(&buf);

	return 0;
}
