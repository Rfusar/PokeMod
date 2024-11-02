.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end


//
OldaleTown_PokemonCenter_1F_EventScript_Gentleman_extra0_str:
    .string "{PLAYER} guarda il portafoglio...$"

OldaleTown_PokemonCenter_1F_EventScript_Gentleman_extra0::
    addmoney 500
    giveitem ITEM_POKE_BALL, 20
    msgbox OldaleTown_PokemonCenter_1F_EventScript_Gentleman_extra0_str
    setflag FLAG_UNUSED_0x021
    release
    end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
    goto_if_unset FLAG_UNUSED_0x021, OldaleTown_PokemonCenter_1F_EventScript_Gentleman_extra0
    end
//

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end


OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC_extra0:
    .string "Mmh cosa c'entra Guccimane\n"
    .string "con quella notte??$"

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Fuso, GucciMane e l'eroina\n"
	.string "La droga... quella notte...$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Fuso è fortissimo qui...$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Fuso t'amooo.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Fuso, ti amooooo tanto.$"

