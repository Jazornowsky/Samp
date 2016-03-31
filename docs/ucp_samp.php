<?php

class ucp_samp
{
	function countChars( $uID_AQ, $samp_users_vip_AQ )
	{
		/* Global modules */
		global $template, $db;
		
		$sql = 'SELECT COUNT(ID) AS char_count FROM ' . $samp_users_vip_AQ . ' WHERE `AccountOwnerID` = ' . $uID_AQ;
		$result = $db->sql_query($sql);
		$char_count = (int) $db->sql_fetchfield('char_count');
		$template->assign_var( 'CHARACTERS_COUNT' , $char_count );
		$db->sql_freeresult($result);
		return $char_count;
	}
	
	function loadChars( $uID_AQ, $mode, $id, $selectedCharacter, $samp_users_vip_AQ, $samp_users_AQ, &$selectedCharacterMatched )
	{
		/* Global modules */
		global $user, $template, $db, $phpEx, $phpbb_root_path;
		
		/* Load user characters */
		$sql = 'SELECT `PlayerName` FROM ' . $samp_users_vip_AQ . ' WHERE `AccountOwnerID` = ' . $uID_AQ;
		$resulttmp = $db->sql_query($sql);
		while($row = $db->sql_fetchrow($resulttmp))
		{
			if( $selectedCharacter == $row['PlayerName'] && $row['PlayerName'] != NULL )
				$selectedCharacterMatched = 1;
			
			$URL_charStats = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "showStats"));
			$URL_charNickChange = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "changeNick"));
			$URL_charDelete = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "deleteCharacter"));
			$URL_charPasswordChange = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "changePassword"));
			$URL_charReactivate = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "reactivate"));
			$URL_charDeactivate = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $row['PlayerName'], 'action' => "deactivate"));
			
			$sql = 'SELECT `Banned` FROM ' . $samp_users_AQ . ' WHERE `PlayerName` = \'' . $row['PlayerName'] . '\'';
			$resulttmp2 = $db->sql_query($sql);
			$row2 = $db->sql_fetchrow($resulttmp2);
			$db->sql_freeresult($resulttmp2);
			
			$sql = 'SELECT `SetToDelete` , `IsOnVacation` FROM `samp_users_other` WHERE `PlayerName` = \'' . $row['PlayerName'] . '\'';
			$resulttmp2 = $db->sql_query($sql);
			$row3 = $db->sql_fetchrow($resulttmp2);
			$db->sql_freeresult($resulttmp2);
			
			$template->assign_block_vars('account_name', array(
				'CHARACTER_NAME' 		=> $row['PlayerName'],
				'URL_CHAR_STATS'		=> $URL_charStats,
				'URL_CHAR_NICK_CHANGE' => $URL_charNickChange,
				'URL_CHAR_DELETE' => $URL_charDelete,
				'URL_CHAR_PASSWORD_CHANGE' => $URL_charPasswordChange,
				'URL_CHAR_REACTIVATE' => $URL_charReactivate,
				'URL_CHAR_DEACTIVATE' => $URL_charDeactivate,
				'BANNED'		=> $row2['Banned'],
				'SET_TO_DELETE'		=> $row3['SetToDelete'],
				'IS_ON_VACATION'		=> $row3['IsOnVacation']
			) );
			
		}
		$db->sql_freeresult($resulttmp);
	}
	
	function main($id, $mode)
	{
		global $user, $template, $db, $phpEx, $phpbb_root_path;
		
		//________[INPUT DATA]________
	
		/* Character on which operations are made ex. name chaning */
		$selectedCharacter = isset($_GET['charName']) ? $_GET['charName'] : '';
		if( $selectedCharacter != NULL )
			$selectedCharacter_AQ = "'$selectedCharacter'";
		$selectedCharacterMatched = 0;
		
		/* Forum user ID */
		$uID = $user->data['user_id'];
		$uID_AQ = "'$uID'";
		
		//__________[TABLES]__________
		$phpbb_users = "phpbb_users";
		$samp_users = "samp_users";
		$samp_users_AQ = "`$samp_users`";
		$samp_users_fueled = "samp_users_fueled";
		$samp_users_fueled_AQ = "`$samp_users_fueled`";
		$samp_users_items = "samp_users_items";
		$samp_users_items_AQ = "`$samp_users_items`";
		$samp_users_items2 = "samp_users_items2";
		$samp_users_items2_AQ = "`$samp_users_items2`";
		$samp_users_items3 = "samp_users_items3";
		$samp_users_items3_AQ = "`$samp_users_items3`";
		$samp_users_jobs = "samp_users_jobs";
		$samp_users_jobs_AQ = "`$samp_users_jobs`";
		$samp_users_keys = "samp_users_keys";
		$samp_users_keys_AQ = "`$samp_users_keys`";
		$samp_users_lic = "samp_users_lic";
		$samp_users_lic_AQ = "`$samp_users_lic`";
		$samp_users_notes = "samp_users_notes";
		$samp_users_notes_AQ = "`$samp_users_notes`";
		$samp_users_other = "samp_users_other";
		$samp_users_other_AQ = "`$samp_users_other`";
		$samp_users_other2 = "samp_users_other2";
		$samp_users_other2_AQ = "`$samp_users_other2`";
		$samp_users_vip = "samp_users_vip";
		$samp_users_vip_AQ = "`$samp_users_vip`";
		$samp_vehicles = "samp_vehicles";
		$samp_vehicles_AQ = "`$samp_vehicles`";
		$samp_houses = "samp_houses";
		$samp_houses_AQ = "`$samp_houses`";
		$samp_factions = "samp_factions";
		$samp_factions_AQ = "`$samp_factions`";
		
		switch($mode)
		{
			case 'char':
			{
				/* Load character list */
				$this->loadChars( $uID_AQ, $mode, $id, $selectedCharacter, $samp_users_vip_AQ, $samp_users_AQ, $selectedCharacterMatched );
				
				$URL_FORM_charDelete = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $selectedCharacter, 'action' => "deleteCharacter") );
				$URL_FORM_charNickChange = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $selectedCharacter, 'action' => "changeNick" ) );
				$URL_FORM_charPasswordChange = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $selectedCharacter, 'action' => "changePassword" ) );
				$URL_FORM_showStats = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $selectedCharacter, 'action' => "showStats" ) );
				$URL_FORM_deactivate = append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'charName' => $selectedCharacter, 'action' => "deactivate" ) );
				$template->assign_vars( array(  
					'SELECTED_CHARACTER' => $selectedCharacter,
					'URL_FORM_CHAR_DELETE' => $URL_FORM_charDelete,
					'URL_FORM_CHAR_NICK_CHANGE' => $URL_FORM_charNickChange,
					'URL_FORM_CHAR_STATS' => $URL_FORM_showStats,
					'URL_FORM_CHAR_DEACTIVATE' => $URL_FORM_deactivate
				) );
				
				/* Get character action */
					$action = isset($_GET['action']) ? $_GET['action'] : '';	
				if( strcmp( $action , "showStats" ) == 0 )
				{
					$template->assign_var( 'ACTION' , $action );	
					
					if( $selectedCharacterMatched )
					{
						$template->assign_var( 'IS_USER_OWNER' , 1 );
						if( $_POST['charBiographyChangeConfirm'] )
						{
							$sql = 'UPDATE `samp_users` SET `Biography` = \'' . $_POST['Biography'] . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
							$db->sql_query($sql);
							
							$template->assign_var( 'BIOGRAPHY_SAVED' , 1 );
						}
					}
					
					$sql = 'SELECT `Level` , `Sex` , `Age` , `Skin` , `PlayingHours` , `Banned` , `Biography` FROM `samp_users` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
					$result = $db->sql_query($sql);
					$row1 = $db->sql_fetchrow($result);
					$db->sql_freeresult($result);
					
					$sql = 'SELECT `AccountOwnerID` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
					$result = $db->sql_query($sql);
					$row2 = $db->sql_fetchrow($result);
					$db->sql_freeresult($result);
					
					$sql = 'SELECT `username` FROM `phpbb_users` WHERE `user_id` = \'' . $row2['AccountOwnerID'] . '\'';
					$result = $db->sql_query($sql);
					$row3 = $db->sql_fetchrow($result);
					$db->sql_freeresult($result);
					
					$template->assign_vars( array (
					'CHARACTER_NAME' => $selectedCharacter,
					'CHARACTER_LEVEL' => $row1['Level'],
					'CHARACTER_SEX' => $row1['Sex'],
					'CHARACTER_SKIN' => $row1['Skin'],
					'CHARACTER_PLAYING_HOURS' => $row1['PlayingHours'],
					'CHARACTER_BANNED' => $row1['Banned'],
					'CHARACTER_OWNER' => $row3['username'],
					'CHARACTER_BIOGRAPHY' => $row1['Biography'],
					'URL_CHARACTER_OWNER_PROFILE' => append_sid("{$phpbb_root_path}memberlist.$phpEx", array('mode' => "viewprofile", 'u' => $row2['AccountOwnerID'] ) )
					) );
				}
				
				/* Check if character belongs to forum ID user */
				if( $selectedCharacterMatched == 1 )
				{
					/* Character nick change */
					if( strcmp( $action , "changeNick" ) == 0 )
					{				
						if( $_POST['charNickChangeConfirm'] == true )
							$template->assign_var( 'CHAR_NICK_CHANGE_CONFIRM' , 1 );
						$template->assign_var( 'ACTION' , $action );	
						
						$newCharacterNick = $_POST['newCharacterNick'];					
						$check = $_POST['check'];
						
						if( $selectedCharacter != NULL  && $newCharacterNick != NULL && $check != NULL )
						{
							$id = 37999;              # numer ID zarejestrowanego klienta
							$code = "PGE2";        # identyfikator us³ug SMS
							$type = "sms";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow

							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							################################################################################			  
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$id."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0)
								$template->assign_var( 'WRONG_CODE', 1 );
							else 
							{
								$sql = 'UPDATE `samp_users` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_items` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_items2` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_items3` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_jobs` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_keys` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_lic` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_notes` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_other` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_other2` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_vip` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_wanted` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_vehicles` SET `Owner` = \'' . $newCharacterNick . '\' WHERE `Owner` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_houses` SET `Owner` = \'' . $newCharacterNick . '\' WHERE `Owner` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_phones` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_users_jobs` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_businesses` SET `Owner` = \'' . $newCharacterNick . '\' WHERE `Owner` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$sql = 'UPDATE `samp_fueled` SET `PlayerName` = \'' . $newCharacterNick . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								$template->assign_var( 'IS_NICK_CHANGED', 1 );
							}
						}
						else if( $check == NULL )
							$template->assign_var( 'EMPTY_CODE', 1 );
						else if( $pNewCharName == NULL )
							$template->assign_var( 'EMPTY_NAME', 1 );
					}
					
					/* Character password change */
					if( strcmp( $action , "changePassword" ) == 0 )
					{
						$template->assign_var( 'ACTION' , $action );	
						
						/* New character password */
						$newCharacterPassword = $_POST['newCharacterPassword'];
						
						if( strlen( $newCharacterPassword ) < 3 )
							$template->assign_var( 'PASSWORD_TOO_SHORT' , 1 );
						else
						{
							if( $_POST['charPasswordChangeConfirm'] == true )
								$template->assign_var( 'CHAR_PASSWORD_CHANGE_CONFIRM' , 1 );
							
							$sql = 'UPDATE `samp_users` SET `Key` = \'' . hash("whirlpool", $newCharacterPassword) . '\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
							$db->sql_query($sql);
						}
					}
					
					/* Character reactivate from vacation */
					if(strcmp($action , "reactivate") == 0)
					{
						$template->assign_var( 'ACTION' , $action );	
						
						$sql = 'UPDATE `samp_users_other` SET `IsOnVacation` = \'0\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
						$db->sql_query($sql);
					}
					/* Character deactivate (vacation) */
					if(strcmp($action , "deactivate") == 0)
					{
						if(isset($_POST['charDeactivateConfirm']))
						{
							$template->assign_var('CHAR_DEACTIVATE_CONFIRM', 1);
						
							$sql = 'UPDATE `samp_users_other` SET `IsOnVacation` = \'1\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
							$db->sql_query($sql);
						}
						
						$template->assign_var( 'ACTION' , $action );	
					}
					
					/* Character delete */
					if( strcmp( $action,  "deleteCharacter" ) == 0 && $selectedCharacter != NULL  )
					{
						if(isset($_POST['charDeleteConfirm']))
						{
							if($_POST['charDeleteConfirm'] == "Tak")
							{
								$template->assign_var( 'CHAR_DELETE_CONFIRM' , 1 );
								
								$sql = 'SELECT `Banned` FROM ' . $samp_users_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								
								if( $row['Banned'] == 0 )
								{
									$sql = 'UPDATE ' . $samp_users_other_AQ . ' SET `SetToDelete` = \'1\' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									$resulttmp = $db->sql_query($sql);
									$db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_fueled_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_items_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_items2_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_items3_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_jobs_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_keys_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_lic_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_notes_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_other_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);	
									
									// $sql = 'DELETE FROM ' . $samp_users_other2_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
									
									// $sql = 'DELETE FROM ' . $samp_users_vip_AQ . ' WHERE `PlayerName` = ' . $selectedCharacter_AQ;
									// $resulttmp = $db->sql_query($sql);
									// $db->sql_freeresult($resulttmp);
								}						
							}
							else
								$action = "";
						}
						$template->assign_var( 'ACTION' , $action );
					}
				}
			}
			case 'regchar':
			{
				if( $this->countChars( $uID_AQ, $samp_users_vip_AQ ) <= 2 )
				{
					/* POST data */
					$characterName = $_POST['characterName'];
					$characterPassword = $_POST['characterPassword'];
					$age = $_POST['age'];
					$sex = $_POST['sex'];
					$server = $_POST['servers'];
					
					$characterName_AQ = "'$characterName'";
				
					/* Check if character name is valid */
					if( $characterName == NULL )
						$template->assign_var( 'CHARACTER_NAME_EMPTY' , 1 );
					else if( preg_match( '/\'/', $characterName ) || preg_match( '/\`/', $characterName ) )
						$template->assign_var( 'CHARACTER_NAME_BAD' , 1 );

					if( $characterName != NULL )
					{
						/* Check if character with entered name already exists */
						$sql = 'SELECT COUNT(ID) AS founder_count FROM `samp_users` WHERE `PlayerName` = ' . $characterName_AQ;
						$resulttmp = $db->sql_query($sql);
						$alreadytaken = (int) $db->sql_fetchfield('founder_count');	
						$db->sql_freeresult($resulttmp);
						$template->assign_var('IS_CHARACTER_NAME_TAKEN', $alreadytaken);
					}
					
					/* Check conditions again */
					if( $alreadytaken == 0 && $characterName != NULL && !preg_match( '/\'/', $characterName ) && !preg_match( '/\`/', $characterName ) )
					{
						/* Other condidtions... */
						if( strlen($characterName) < 8 )
							$template->assign_var( 'CHARACTER_NAME_TOO_SHORT' , 1 );		
						else if( strlen($characterPassword) < 3 )
							$template->assign_var( 'CHARACTER_PASSWORD_TOO_SHORT', 1 );
						else
						{
							$characterPassword = hash("whirlpool", $characterPassword);
							$characterPassword_AQ = "'$characterPassword'";
							if($server == "vigilante")
							{
								$sql = 'INSERT INTO `samp_users` ( `PlayerName` , `Key`, `Age`, `Sex`,`Biography` ) VALUES ( ' . $characterName_AQ . ' , ' . $characterPassword_AQ . ' , \'' . $age . '\' , \'' . $sex . '\' , " " ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_items` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_items2` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_items3` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_jobs` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_keys` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_lic` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_notes` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_other` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_other2` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `samp_users_vip` (`PlayerName` , `AccountOwnerID`) VALUES ( ' . $characterName_AQ . ' , ' . $uID . ' ) ';
								$db->sql_query($sql);
							}
							else
							{
								$sql = 'INSERT INTO `test`.`samp_users` ( `PlayerName` , `Key`, `Age`, `Sex`,`Biography` ) VALUES ( ' . $characterName_AQ . ' , ' . $characterPassword_AQ . ' , \'' . $age . '\' , \'' . $sex . '\' , " " ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_items` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_items2` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_items3` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_jobs` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_keys` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_lic` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_notes` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_other` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_other2` (`PlayerName`) VALUES ( ' . $characterName_AQ . ' ) ';
								$db->sql_query($sql);
								$sql = 'INSERT INTO `test`.`samp_users_vip` (`PlayerName` , `AccountOwnerID`) VALUES ( ' . $characterName_AQ . ' , ' . $uID . ' ) ';
								$db->sql_query($sql);
							}
							
							$template->assign_var( 'CHARACTER_CREATED' , 1 );
						}
					}
				}
			}
			case 'vip':
			{
				$vipType = isset($_GET['vip']) ? $_GET['vip'] : '';
				$template->assign_vars(array( 'URL_FORM_VIPALLSSPR' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'vip' => $vipType ) ) ) );
				/* Load user WParty points */
				$sql = 'SELECT `wppoints` FROM ' . $phpbb_users . ' WHERE `user_id` = ' . $uID_AQ;
				$resulttmp = $db->sql_query($sql);
				$row = $db->sql_fetchrow($resulttmp);
				$wppoints = $row['wppoints'];	
				$template->assign_vars(array( 'VIP_POINTS' => $wppoints ) );
				
				if( $vipType != 0 )
				{
					$template->assign_var( 'VIP_SELECTED' , $vipType );
					
					/* Character on which operations are made */
					$selectedCharacter = $_POST['character'];
					
					/* Dotpay code verification */
					$check = $_POST['check'];
					
					/* Characters data */
					$characterArray = array();	
					
					/* How many characters user have */
					$charactersCount = 0;
					
					/* How many death characters user have */
					$charactersDeathCount = 0;
					
					/* Load character list */
					$sql = 'SELECT `PlayerName` FROM ' . $samp_users_vip_AQ . ' WHERE `AccountOwnerID` = ' . $uID_AQ;
					$resulttmp = $db->sql_query($sql);				
					while($row = $db->sql_fetchrow($resulttmp))
					{
						$characterArray[$charactersCount]['Name'] = $row['PlayerName'];
						$charactersCount++;
					}					
					
					$db->sql_freeresult($resulttmp);
					for( $i = 0; $i < $charactersCount; $i++ )
					{
						$sql = 'SELECT `Banned` FROM `samp_users` WHERE `PlayerName` = \'' . $characterArray[$i]['Name'] . '\'';
						$resulttmp = $db->sql_query($sql);
						$row = $db->sql_fetchrow($resulttmp);
						$db->sql_freeresult($resulttmp);
						
						$characterArray[$i]['Banned'] = $row['Banned'];
						
						$sql = 'SELECT `CharacterDeath` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $characterArray[$i]['Name'] . '\'';
						$resulttmp = $db->sql_query($sql);
						$row = $db->sql_fetchrow($resulttmp);
						$db->sql_freeresult($resulttmp);
						
						$characterArray[$i]['CharacterDeath'] = $row['CharacterDeath'];							
						if( $characterArray[$i]['CharacterDeath'] > 0 )
							$charactersDeathCount++;
							
						$sql = 'SELECT `SetToDelete` FROM `samp_users_other` WHERE `PlayerName` = \'' . $characterArray[$i]['Name'] . '\'';
						$resulttmp = $db->sql_query($sql);
						$row = $db->sql_fetchrow($resulttmp);
						$db->sql_freeresult($resulttmp);
						
						$characterArray[$i]['SetToDelete'] = $row['SetToDelete'];
					}
					$template->assign_var( 'CHARACTERS_D_COUNT', $charactersDeathCount );
					
					for( $i = 0; $i < $charactersCount; $i++ )
					{
						$template->assign_block_vars('account_vipall', array( 
							'CHARACTER_NAME' => $characterArray[$i]['Name'],
							'CHARACTER_BANNED' => $characterArray[$i]['Banned'],
							'CHARACTER_SET_TO_DELETE' => $characterArray[$i]['SetToDelete'],
							'CHARACTER_DEATH' => $characterArray[$i]['CharacterDeath']
						) );
					}					
					
					/* BUY 890 WPPOINTS */
					if( $vipType == 1 )
					{
						if( $check != NULL )
						{
							$idDP = 60428;              # numer ID zarejestrowanego klienta
							$code = "WPA1";        # identyfikator us³ug SMS
							$type = "sms";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow

							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							################################################################################			  
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0) 
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=890;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 1780 WPPOINTS */
					if( $vipType == 2 )
					{
						if( $check != NULL )
						{
							$idDP = 60428;              # numer ID zarejestrowanego klienta
							$code = "WPA2";        # identyfikator us³ug SMS
							$type = "sms";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow

							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							################################################################################			  
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0) 
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=1905;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 3560 WPPOINTS */
					if( $vipType == 3 )
					{
						if( $check != NULL )
						{
							$idDP = 60428;              # numer ID zarejestrowanego klienta
							$code = "WPA3";        # identyfikator us³ug SMS
							$type = "sms";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow

							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							################################################################################			  
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0) 
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=3810;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 4450 WPPOINTS */
					if( $vipType == 4 )
					{
						if( $check != NULL )
						{
							$idDP = 60428;              # numer ID zarejestrowanego klienta
							$code = "WPA4";        # identyfikator us³ug SMS
							$type = "sms";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow

							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							################################################################################			  
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0) 
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=4760;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 2314 WPPOINTS */
					else if( $vipType == 5 )
					{	
						if( $check != NULL )
						{
							$idDP = 60428;              # numer ID zarejestrowanego klienta
							$code = "wprp1";        # identyfikator us³ug SMS
							$type = "C1";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow
					
							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							#################################################################################
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0)
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=2476;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 6764 WPPOINTS */
					else if( $vipType == 6 )
					{	
						if( $check != NULL )
						{
							$idDP = 37999;              # numer ID zarejestrowanego klienta
							$code = "wprp2";        # identyfikator us³ug SMS
							$type = "C1";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow
					
							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							#################################################################################
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0)
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=7237;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* BUY 8900 WPPOINTS */
					else if( $vipType == 7 )
					{	
						if( $check != NULL )
						{
							$idDP = 37999;              # numer ID zarejestrowanego klienta
							$code = "wprp3";        # identyfikator us³ug SMS
							$type = "C1";          # typ konta: C1 - 8 znakowy kod bezobs³ugowy
										   # typ konta: sms dla sprawdzania SMSow
					
							# gdy sprawdzane bêd¹ zarówno konta smsowe jak i konta przy p³atnoœciach kart¹
							# to nale¿y wtedy u¿yæ zapisu:
							# $type = "c1,sms";

							#
							# przy sprawdzaniu kilku kont o ró¿nych identyfikatorach nale¿y u¿yæ zapisu:
							# $code = "abcd1,abcd2,kody2,kody6"; 

							$del=1;   # je¿eli kod ma byæ skasowany od razu po sprawdzeniu to ustaw wartoœæ na 1
							#################################################################################
							$handle = fopen("http://dotpay.pl/check_code.php?id=".$idDP."&code=".$code."&check=".$check."&type=".$type."&del=".$del, 'r');
							$status = fgets($handle, 8);
							$czas_zycia = fgets($handle, 24);
							fclose($handle);
							$czas_zycia = rtrim($czas_zycia);

							if ($status == 0)
								$template->assign_vars(array( 'WRONG_CODE' => 1 ) );
							else 
							{
								$template->assign_var( 'POINTS_BOUGHT', 1 );
								$wppoints+=9523;
								$wppoints_AQ = "'$wppoints'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = ' . $wppoints_AQ . ' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $check == NULL )
							$template->assign_vars(array( 'EMPTY_CODE' => 1 ) );
					}
					
					/* VIP BASIC */
					if( $vipType == 8 )
					{
						if( $selectedCharacter != NULL )
						{
							if ($wppoints - 1750 < 0) 
								$template->assign_vars(array( 'LOW_POINTS' => 1 ) );
							else 
							{
								$template->assign_var( 'VIP_ACTIVATED', 1 );
								$sql = 'SELECT `VipAFKT` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								$date = $row['VipAFKT'];
								$date+=30;
								$date_AQ = "'$date'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `samp_users_vip` SET `VipAFKT` = ' . $date_AQ . ' , `VipExpT` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 1750;
								$lognfo = 'Aktywowal vip basic dla ' . $selectedCharacter;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}

					/* GARAZ */
					else if( $vipType == 9 )
					{
						if( $selectedCharacter != NULL )
						{
							if ($wppoints - 3400 < 0) 
								$template->assign_var( 'LOW_POINTS', 1 );
							else 
							{
								$template->assign_var( 'GARAGE_ACTIVATED', 1 );
								$sql = 'SELECT `VipGarage` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								$date = $row['VipGarage'];
								$date+=1;
								$date_AQ = "'$date'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `samp_users_vip` SET `VipGarage` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 3400;
								$lognfo = 'Aktywowal garaz dla ' . $selectedCharacter;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}
					
					/* VIP ITEM */
					else if( $vipType == 10 )
					{
						if( $selectedCharacter != NULL )
						{							
							if ($wppoints - 600 < 0) 
								$template->assign_var( 'LOW_POINTS', 1 );
							else 
							{
								$template->assign_var( 'VIPITEM_ACTIVATED', 1 );
								
								$sql = 'SELECT `VipItem` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								$db->sql_freeresult($resulttmp);								
								$date = $row['VipItem'];								
								$date+=30;
								$date_AQ = "'$date'";
								
								$sql = 'UPDATE `samp_users_vip` SET `VipItem` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 600;
								$lognfo = 'Aktywowal vip item dla ' . $selectedCharacter;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}
					
					/* VIP RESURRECTION */
					else if( $vipType == 11 )
					{
						$charDeath = $_POST['charDeath'];
						if( $selectedCharacter != NULL && $charDeath > 0)
						{							
							if ($wppoints - 600 < 0) 
								$template->assign_var( 'LOW_POINTS', 1 );
							else 
							{
								$template->assign_var( 'RES_ACTIVATED', 1 );
								
								$sql = 'UPDATE `samp_users_vip` SET `CharacterDeath` = \'0\' , `CharacterDying` = \'0\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								$sql = 'UPDATE `samp_users` SET `CrashX` = \'1358.0\' , `CrashY` = \'420.0\' , `CrashZ` = \'20.1\' , `CrashW` = \'0\' , `CrashInt` = \'0\' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 600;
								$lognfo = 'Aktywowal wskrzeszenie dla ' . $selectedCharacter;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}
					
					/* NEON SMS */
					else if( $vipType == 12 )
					{
						$varColor = $_GET['varColor'];
						$template->assign_vars(array( 'U_VIEW_SAMP_VIPNEOSSPR' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'vip' => $vipType, 'varColor' => $varColor ) ) ) );
						
						if( $varColor == "RED" )
							$template->assign_var( 'NEON_COLOR', 1 );
						else if( $varColor == "BLUE" )
							$template->assign_var( 'NEON_COLOR', 2 );
						else if( $varColor == "GREEN" )
							$template->assign_var( 'NEON_COLOR', 3 );
						else if( $varColor == "YELLOW" )
							$template->assign_var( 'NEON_COLOR', 4 );
						else if( $varColor == "PINK" )
							$template->assign_var( 'NEON_COLOR', 5 );
						else if( $varColor == "WHITE" )
							$template->assign_var( 'NEON_COLOR', 6 );
						else if( $varColor == "HALOGENLIGHT" )
							$template->assign_var( 'NEON_COLOR', 7 );
						else if( $varColor == "POINTLIGHTWHITE" )
							$template->assign_var( 'NEON_COLOR', 8 );
						else if( $varColor == "POINTLIGHTRED" )
							$template->assign_var( 'NEON_COLOR', 9 );
						else if( $varColor == "POINTLIGHTGREEN" )
							$template->assign_var( 'NEON_COLOR', 10 );
						else if( $varColor == "POINTLIGHTBLUE" )
							$template->assign_var( 'NEON_COLOR', 11 );
						
						if( $selectedCharacter != NULL )
						{							
							if ($wppoints - 800 < 0) 
								$template->assign_var( 'LOW_POINTS', 1 );
							else 
							{
								$template->assign_var( 'NEON_ACTIVATED', 1 );
								
								if( $varColor == "RED" )
									$sql = 'SELECT `VipRedNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "BLUE" )
									$sql = 'SELECT `VipBlueNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "GREEN" )
									$sql = 'SELECT `VipGreenNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "YELLOW" )
									$sql = 'SELECT `VipYellowNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "PINK" )
									$sql = 'SELECT `VipPinkNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "WHITE" )
									$sql = 'SELECT `VipWhiteNeon` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "HALOGENLIGHT" )
									$sql = 'SELECT `VipHalogenLight` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "POINTLIGHTWHITE" )
									$sql = 'SELECT `VipWhitePointLight` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "POINTLIGHTRED" )
									$sql = 'SELECT `VipRedPointLight` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "POINTLIGHTGREEN" )
									$sql = 'SELECT `VipGreenPointLight` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								else if( $varColor == "POINTLIGHTBLUE" )
									$sql = 'SELECT `VipBluePointLight` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								$db->sql_freeresult($resulttmp);
								
								if( $varColor == "RED" )
									$date = $row['VipRedNeon'];
								else if( $varColor == "BLUE" )
									$date = $row['VipBlueNeon'];
								else if( $varColor == "GREEN" )
									$date = $row['VipGreenNeon'];
								else if( $varColor == "YELLOW" )
									$date = $row['VipYellowNeon'];
								else if( $varColor == "PINK" )
									$date = $row['VipPinkNeon'];
								else if( $varColor == "WHITE" )
									$date = $row['VipWhiteNeon'];
								else if( $varColor == "HALOGENLIGHT" )
									$date = $row['VipHalogenLight'];
								else if( $varColor == "POINTLIGHTWHITE" )
									$date = $row['VipWhitePointLight'];
								else if( $varColor == "POINTLIGHTRED" )
									$date = $row['VipRedPointLight'];
								else if( $varColor == "POINTLIGHTGREEN" )
									$date = $row['VipGreenPointLight'];
								else if( $varColor == "POINTLIGHTBLUE" )
									$date = $row['VipBluePointLight'];
								
								$date+=2;
								$date_AQ = "'$date'";
								
								if( $varColor == "RED" )
									$sql = 'UPDATE `samp_users_vip` SET `VipRedNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "BLUE" )
									$sql = 'UPDATE `samp_users_vip` SET `VipBlueNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "GREEN" )
									$sql = 'UPDATE `samp_users_vip` SET `VipGreenNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "YELLOW" )
									$sql = 'UPDATE `samp_users_vip` SET `VipYellowNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "PINK" )
									$sql = 'UPDATE `samp_users_vip` SET `VipPinkNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "WHITE" )
									$sql = 'UPDATE `samp_users_vip` SET `VipWhiteNeon` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "HALOGENLIGHT" )
									$sql = 'UPDATE `samp_users_vip` SET `VipHalogenLight` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "POINTLIGHTWHITE" )
									$sql = 'UPDATE `samp_users_vip` SET `VipWhitePointLight` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "POINTLIGHTRED" )
									$sql = 'UPDATE `samp_users_vip` SET `VipRedPointLight` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "POINTLIGHTGREEN" )
									$sql = 'UPDATE `samp_users_vip` SET `VipGreenPointLight` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								if( $varColor == "POINTLIGHTBLUE" )
									$sql = 'UPDATE `samp_users_vip` SET `VipBluePointLight` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';

								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 800;
								$lognfo = 'Aktywowal obiekt dla ' . $selectedCharacter . ', obiekt/kolor neonu: ' . $varColor;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}
				
					/* OBJECTS */
					else if( $vipType == 14 )
					{
						if( $selectedCharacter != NULL )
						{
							if ($wppoints - 2000 < 0) 
								$template->assign_var( 'LOW_POINTS', 1 );
							else 
							{
								$template->assign_var( 'OBJECTS_ACTIVATED', 1 );
								$sql = 'SELECT `VipCustomObjects` FROM `samp_users_vip` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$resulttmp = $db->sql_query($sql);
								$row = $db->sql_fetchrow($resulttmp);
								$date = $row['VipCustomObjects'];
								$date+=25;
								$date_AQ = "'$date'";
								$db->sql_freeresult($resulttmp);
								
								$sql = 'UPDATE `samp_users_vip` SET `VipCustomObjects` = ' . $date_AQ . ' WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
								$db->sql_query($sql);
								
								/* Take player WParty points */
								$wppoints -= 2000;
								$lognfo = 'Aktywowal obiekty dla ' . $selectedCharacter;
								add_log('user', $row['user_id'], $lognfo);
								$sql = 'UPDATE `phpbb_users` SET `wppoints` = \'' . $wppoints . '\' WHERE `user_id` = \'' . $uID . '\'';
								$db->sql_query($sql);
							}
						}
						else if( $selectedCharacter == NULL )
							$template->assign_vars(array( 'EMPTY_NAME' => 1 ) );
					}
				}
			}		
			case 'faction':
			{
				$selectedCharacter = isset($_POST["characterName"]) ? $_POST['characterName'] : '';
				if($selectedCharacter == NULL)
				{
					/* Characters data */
					$characterArray = array();
					
					/* How many characters user have */
					$charactersCount = 0;
					
					$sql = 'SELECT `PlayerName` FROM ' . $samp_users_vip_AQ . ' WHERE `AccountOwnerID` = ' . $uID_AQ;
					$resulttmp = $db->sql_query($sql);
					while($row = $db->sql_fetchrow($resulttmp))
					{
						$characterArray[$charactersCount]['Name'] = $row['PlayerName'];
						$charactersCount++;
					}
					$db->sql_freeresult($resulttmp);
					
					for( $i = 0; $i < $charactersCount; $i++ )
					{
						$sql = 'SELECT `Banned` FROM `samp_users` WHERE `PlayerName` = \'' . $characterArray[$i]['Name'] . '\'';
						$resulttmp = $db->sql_query($sql);
						$row = $db->sql_fetchrow($resulttmp);
						$db->sql_freeresult($resulttmp);
						$characterArray[$i]['Banned'] = $row['Banned'];		
						$db->sql_freeresult($resulttmp);
					}
					
					for($i = 0; $i < $charactersCount; $i++)
					{
						$sql = 'SELECT `SetToDelete` FROM `samp_users_other` WHERE `PlayerName` = \'' . $characterArray[$i]['Name'] . '\'';
						$resulttmp = $db->sql_query($sql);
						$row = $db->sql_fetchrow($resulttmp);
						$db->sql_freeresult($resulttmp);
						$characterArray[$i]['SetToDelete'] = $row['SetToDelete'];
						$db->sql_freeresult($resulttmp);
					}
					
					for( $i = 0; $i < $charactersCount; $i++ )
					{
						$template->assign_block_vars('account_data', array( 
							'CHARACTER_NAME' => $characterArray[$i]['Name'],
							'CHARACTER_BANNED' => $characterArray[$i]['Banned'],
							'CHARACTER_SET_TO_DELETE' => $characterArray[$i]['SetToDelete']
						) );
					}
				}
				else
				{
					$template->assign_vars(array( 
						'CHARACTER_SELECTED' => 1,
						'CHARACTER_NAME' => $selectedCharacter
					) );

					if( (isset($_GET['save']) ? $_GET['save'] : 0) == 1 )
					{
						$factionl = $_POST['FACTIONID'] + 1;
						$sql = 'UPDATE `samp_factions` SET `Rank1` = \'' . $_POST['RANK1NAME'] . '\' , `Rank2` = \'' . $_POST['RANK2NAME'] . '\' , `Rank3` = \'' . $_POST['RANK3NAME'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Rank4` = \'' . $_POST['RANK4NAME'] . '\' , `Rank5` = \'' . $_POST['RANK5NAME'] . '\' , `Rank6` = \'' . $_POST['RANK6NAME'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Rank7` = \'' . $_POST['RANK7NAME'] . '\' , `Rank8` = \'' . $_POST['RANK8NAME'] . '\' , `Rank9` = \'' . $_POST['RANK9NAME'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Rank10` = \'' . $_POST['RANK10NAME'] . '\' , `Skin1` = \'' . $_POST['RANK1SKIN'] . '\' , `Skin2` = \'' . $_POST['RANK2SKIN'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Skin3` = \'' . $_POST['RANK3SKIN'] . '\' , `Skin4` = \'' . $_POST['RANK4SKIN'] . '\' , `Skin5` = \'' . $_POST['RANK5SKIN'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Skin6` = \'' . $_POST['RANK6SKIN'] . '\' , `Skin7` = \'' . $_POST['RANK7SKIN'] . '\' , `Skin8` = \'' . $_POST['RANK8SKIN'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						$sql = 'UPDATE `samp_factions` SET `Skin9` = \'' . $_POST['RANK9SKIN'] . '\' , `Skin10` = \'' . $_POST['RANK10SKIN'] . '\' , `JoinRank` = \'' . $_POST['RANKJOIN'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						if( empty( $_POST['USESKINS'] ) ) { $useskins = 0; } else { $useskins = 1; }
						$sql = 'UPDATE `samp_factions` SET `UseSkins` = \'' . $useskins . '\' , `RankAmount` = \'' . $_POST['RANKAMOUNT'] . '\' WHERE `ID` = \'' . $factionl . '\'';
						$resulttmp = $db->sql_query($sql);
						$db->sql_freeresult($resulttmp);
						
						if( ( preg_match( "/[0-9]{1,3}/", $_POST['RANK1PAY'] ) && ( $_POST['RANK1PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK1PAY']) )
						{
							if( empty($_POST['RANK1PAY']) ) $_POST['RANK1PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank1` = \'' . $_POST['RANK1PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK1PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK2PAY'] ) && ( $_POST['RANK2PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK2PAY']) )
						{
							if( empty($_POST['RANK2PAY']) ) $_POST['RANK2PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank2` = \'' . $_POST['RANK2PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else { $template->assign_var( 'RANK2PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK3PAY'] ) && ( $_POST['RANK3PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK3PAY']) )
						{
							if( empty($_POST['RANK3PAY']) ) $_POST['RANK3PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank3` = \'' . $_POST['RANK3PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK3PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK4PAY'] ) && ( $_POST['RANK4PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK4PAY']) )
						{
							if( empty($_POST['RANK4PAY']) ) $_POST['RANK4PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank4` = \'' . $_POST['RANK4PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK4PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK5PAY'] ) && ( $_POST['RANK5PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK5PAY']) )
						{
							if( empty($_POST['RANK5PAY']) ) $_POST['RANK5PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank5` = \'' . $_POST['RANK5PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK5PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK6PAY'] ) && ( $_POST['RANK6PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK6PAY']) )
						{
							if( empty($_POST['RANK6PAY']) ) $_POST['RANK6PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank6` = \'' . $_POST['RANK6PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK6PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK7PAY'] ) && ( $_POST['RANK7PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK7PAY']) )
						{
							if( empty($_POST['RANK7PAY']) ) $_POST['RANK7PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank7` = \'' . $_POST['RANK7PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK7PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK8PAY'] ) && ( $_POST['RANK8PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK8PAY']) )
						{
							if( empty($_POST['RANK8PAY']) ) $_POST['RANK8PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank8` = \'' . $_POST['RANK8PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK8PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK9PAY'] ) && ( $_POST['RANK9PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK9PAY']) )
						{
							if( empty($_POST['RANK9PAY']) ) $_POST['RANK9PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank9` = \'' . $_POST['RANK9PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK9PAYBV', 1 ); }
						if( (preg_match( "/[0-9]{1,3}/", $_POST['RANK10PAY'] ) && ( $_POST['RANK10PAY'] <= 350 || $_POST['FACTIONID'] >= 14 ) ) || empty($_POST['RANK10PAY']) )
						{
							if( empty($_POST['RANK10PAY']) ) $_POST['RANK10PAY'] = 0;
							$sql = 'UPDATE `samp_factions_payrank` SET `Rank10` = \'' . $_POST['RANK10PAY'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$db->sql_query($sql);
						}
						else	{ $template->assign_var( 'RANK10PAYBV', 1 ); }
						
						if( $_POST['TYPE'] == 1 || $_POST['TYPE'] == 3 )
						{
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank1` = \'' . $_POST['GUN1RANK1'] . '\' , `Gun2Rank1` = \'' . $_POST['GUN2RANK1'] . '\' , `Gun3Rank1` = \'' . $_POST['GUN3RANK1'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank2` = \'' . $_POST['GUN1RANK2'] . '\' , `Gun2Rank2` = \'' . $_POST['GUN2RANK2'] . '\' , `Gun3Rank2` = \'' . $_POST['GUN3RANK2'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank3` = \'' . $_POST['GUN1RANK3'] . '\' , `Gun2Rank3` = \'' . $_POST['GUN2RANK3'] . '\' , `Gun3Rank3` = \'' . $_POST['GUN3RANK3'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank4` = \'' . $_POST['GUN1RANK4'] . '\' , `Gun2Rank4` = \'' . $_POST['GUN2RANK4'] . '\' , `Gun3Rank4` = \'' . $_POST['GUN3RANK4'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank5` = \'' . $_POST['GUN1RANK5'] . '\' , `Gun2Rank5` = \'' . $_POST['GUN2RANK5'] . '\' , `Gun3Rank5` = \'' . $_POST['GUN3RANK5'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank6` = \'' . $_POST['GUN1RANK6'] . '\' , `Gun2Rank6` = \'' . $_POST['GUN2RANK6'] . '\' , `Gun3Rank6` = \'' . $_POST['GUN3RANK6'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank7` = \'' . $_POST['GUN1RANK7'] . '\' , `Gun2Rank7` = \'' . $_POST['GUN2RANK7'] . '\' , `Gun3Rank7` = \'' . $_POST['GUN3RANK7'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank8` = \'' . $_POST['GUN1RANK8'] . '\' , `Gun2Rank8` = \'' . $_POST['GUN2RANK8'] . '\' , `Gun3Rank8` = \'' . $_POST['GUN3RANK8'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank9` = \'' . $_POST['GUN1RANK9'] . '\' , `Gun2Rank9` = \'' . $_POST['GUN2RANK9'] . '\' , `Gun3Rank9` = \'' . $_POST['GUN3RANK9'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons` SET `Gun1Rank10` = \'' . $_POST['GUN1RANK10'] . '\' , `Gun2Rank10` = \'' . $_POST['GUN2RANK10'] . '\' , `Gun3Rank10` = \'' . $_POST['GUN3RANK10'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank1` = \'' . $_POST['AMMO1RANK1'] . '\' , `Ammo2Rank1` = \'' . $_POST['AMMO2RANK1'] . '\' , `Ammo3Rank1` = \'' . $_POST['AMMO3RANK1'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank2` = \'' . $_POST['AMMO1RANK2'] . '\' , `Ammo2Rank2` = \'' . $_POST['AMMO2RANK2'] . '\' , `Ammo3Rank2` = \'' . $_POST['AMMO3RANK2'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank3` = \'' . $_POST['AMMO1RANK3'] . '\' , `Ammo2Rank3` = \'' . $_POST['AMMO2RANK3'] . '\' , `Ammo3Rank3` = \'' . $_POST['AMMO3RANK3'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank4` = \'' . $_POST['AMMO1RANK4'] . '\' , `Ammo2Rank4` = \'' . $_POST['AMMO2RANK4'] . '\' , `Ammo3Rank4` = \'' . $_POST['AMMO3RANK4'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank5` = \'' . $_POST['AMMO1RANK5'] . '\' , `Ammo2Rank5` = \'' . $_POST['AMMO2RANK5'] . '\' , `Ammo3Rank5` = \'' . $_POST['AMMO3RANK5'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank6` = \'' . $_POST['AMMO1RANK6'] . '\' , `Ammo2Rank6` = \'' . $_POST['AMMO2RANK6'] . '\' , `Ammo3Rank6` = \'' . $_POST['AMMO3RANK6'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank7` = \'' . $_POST['AMMO1RANK7'] . '\' , `Ammo2Rank7` = \'' . $_POST['AMMO2RANK7'] . '\' , `Ammo3Rank7` = \'' . $_POST['AMMO3RANK7'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank8` = \'' . $_POST['AMMO1RANK8'] . '\' , `Ammo2Rank8` = \'' . $_POST['AMMO2RANK8'] . '\' , `Ammo3Rank8` = \'' . $_POST['AMMO3RANK8'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank9` = \'' . $_POST['AMMO1RANK9'] . '\' , `Ammo2Rank9` = \'' . $_POST['AMMO2RANK9'] . '\' , `Ammo3Rank9` = \'' . $_POST['AMMO3RANK9'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
							$sql = 'UPDATE `samp_factions_weapons2` SET `Ammo1Rank10` = \'' . $_POST['AMMO1RANK10'] . '\' , `Ammo2Rank10` = \'' . $_POST['AMMO2RANK10'] . '\' , `Ammo3Rank10` = \'' . $_POST['AMMO3RANK10'] . '\' WHERE `FactionID` = \'' . $_POST['FACTIONID'] . '\'';
							$resulttmp = $db->sql_query($sql);
							$db->sql_freeresult($resulttmp);
						}						
					}
					$template->assign_vars(array( 
						'U_VIEW_SAMP_SAVE' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'save' => 1 ) ),
						'U_VIEW_SAMP_MLIST' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'mlist' => 1 ) ),
						'U_VIEW_SAMP_BLIST' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'blist' => 1 ) ),
						'U_VIEW_SAMP_VLIST' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'vlist' => 1 ) ),
						'U_VIEW_SAMP_SMLIST' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'mlist' => 1, 'smlist' => 1 ) )
					) );
					$sql = 'SELECT `Faction` , `Rank` FROM `samp_users` WHERE `PlayerName` = \'' . $selectedCharacter . '\'';
					$resulttmp = $db->sql_query($sql);
					$row = $db->sql_fetchrow($resulttmp);
					$db->sql_freeresult($resulttmp);
					$template->assign_vars( array(
						'CHAR_FACTION' => $row['Faction'],
						'CHAR_RANK' => $row['Rank']
					) );
					$faction = $row['Faction'];
					$factionl = $faction+1;
					$rank = $row['Rank'];
					if( $faction != 255 )
					{
						$mlist = isset($_GET['mlist']) ? $_GET['mlist'] : 0;
						$blist = isset($_GET['blist']) ? $_GET['blist'] : 0;
						$vlist = isset($_GET['vlist']) ? $_GET['vlist'] : 0;
						$mname = isset($_GET['mname']) ? $_GET['mname'] : '';
						$rankup = isset($_GET['rankup']) ? $_GET['rankup'] : 0;
						$rankdwn = isset($_GET['rankdwn']) ? $_GET['rankdwn'] : 0;
						$delete = isset($_GET['deletem']) ? $_GET['deletem'] : 0;
						if( $mname != NULL && $selectedCharacter != $mname )
						{
							if( $rankup && $rankup <= 9 )
							{
								$rankup++;
								$sql = 'UPDATE `samp_users` SET `Rank` = \'' . $rankup . '\' WHERE `PlayerName` = \'' . $mname . '\'';
								$db->sql_query($sql);
							}
							if( $rankdwn && $rankdwn >= 2 )
							{
								$rankdwn--;
								$sql = 'UPDATE `samp_users` SET `Rank` = \'' . $rankdwn . '\' WHERE `PlayerName` = \'' . $mname . '\'';
								$db->sql_query($sql);
							}
							if( $delete )
							{
								$sql = 'UPDATE `samp_users` SET `Faction` = \'255\' WHERE `PlayerName` = \'' . $mname . '\'';
								$db->sql_query($sql);
							}
						}
						if( $blist )
						{
							$template->assign_var( 'SHOW_BLIST', 1 );
							$sql = 'SELECT `ID`, `BusinessName` , `Owner` , `Owned` , `BizPrice` , `EntranceCost` , `BizType` , `MaxVehicles`, `ExitInterior` FROM `samp_businesses` WHERE `ID` != \'0\'';
							$resulttmp = $db->sql_query($sql);
							while( $row = $db->sql_fetchrow($resulttmp) )
							{
								$row['ID'] = $row['ID']-1;
								$template->assign_block_vars('businesses', array(
									'B_ID' => $row['ID'],
									'B_NAME' => $row['BusinessName'],
									'B_OWNER' => $row['Owner'],
									'B_OWNED' => $row['Owned'],
									'B_PRICE' => $row['BizPrice'],
									'B_ENTRANCECOST' => $row['EntranceCost'],
									'B_TYPE' => $row['BizType'],
									'B_MAXVEH' => $row['MaxVehicles'],
									'B_INT' => $row['ExitInterior']
								) );
							}
							$db->sql_freeresult($resulttmp);
						}
						if( $vlist )
						{
							$template->assign_var( 'SHOW_VLIST', 1 );
							$sql = 'SELECT `VehModel` , `CarSerial` FROM `samp_vehicles` WHERE `VehFaction` = \'' . $faction . '\'';
							$resulttmp = $db->sql_query($sql);
							while( $row = $db->sql_fetchrow($resulttmp) )
							{
								$template->assign_block_vars('faction_vehicles', array(
									'VEH_MODEL' => $row['VehModel'],
									'VEH_SERIAL' => $row['CarSerial']
								));
							}
							$db->sql_freeresult($resulttmp);
						}
						if( $mlist )
						{
							$template->assign_var( 'SHOW_MLIST', 1 );
							$sql = 'SELECT `PlayerName`, `Rank` FROM `samp_users` WHERE `Faction` = \'' . $faction . '\'';
							$resulttmp = $db->sql_query($sql);
							while( $row = $db->sql_fetchrow($resulttmp) )
							{
								$template->assign_block_vars('faction_members', array(
									'MEMBER_NAME' 		=> $row['PlayerName'],
									'MEMBER_RANK'		=> $row['Rank'],
									'RANK_UP' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'mlist' => 1, 'mname' => $row['PlayerName'], 'rankup' => $row['Rank'] ) ),
									'RANK_DWN' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'mlist' => 1, 'mname' => $row['PlayerName'], 'rankdwn' => $row['Rank'] ) ),
									'M_DELETE' => append_sid("{$phpbb_root_path}ucp.$phpEx", array('i' => $id, 'mode' => $mode, 'mlist' => 1, 'mname' => $row['PlayerName'], 'deletem' => 1 ) )
								) );
							}
							$db->sql_freeresult($resulttmp);
						}
						if( !$mlist )
						{
							$sql = 'SELECT * FROM `samp_factions` WHERE `ID` = \'' . $factionl . '\'';
							$resulttmp = $db->sql_query($sql);
							$row = $db->sql_fetchrow($resulttmp);
							$db->sql_freeresult($resulttmp);
							$template->assign_vars( array(
								'FACTIONID' => $faction,
								'RANK1NAME' => $row['Rank1'],
								'RANK2NAME' => $row['Rank2'],
								'RANK3NAME' => $row['Rank3'],
								'RANK4NAME' => $row['Rank4'],
								'RANK5NAME' => $row['Rank5'],
								'RANK6NAME' => $row['Rank6'],
								'RANK7NAME' => $row['Rank7'],
								'RANK8NAME' => $row['Rank8'],
								'RANK9NAME' => $row['Rank9'],
								'RANK10NAME' => $row['Rank10'],
								'RANK1SKIN' => $row['Skin1'],
								'RANK2SKIN' => $row['Skin2'],
								'RANK3SKIN' => $row['Skin3'],
								'RANK4SKIN' => $row['Skin4'],
								'RANK5SKIN' => $row['Skin5'],
								'RANK6SKIN' => $row['Skin6'],
								'RANK7SKIN' => $row['Skin7'],
								'RANK8SKIN' => $row['Skin8'],
								'RANK9SKIN' => $row['Skin9'],
								'RANK10SKIN' => $row['Skin10'],
								'RANKJOIN' => $row['JoinRank'],
								'USESKINS' => $row['UseSkins'],
								'RANKAMOUNT' => $row['RankAmount'],
								'NAME' => $row['Name'],
								'BANK' => $row['Bank'],
								'TYPE' => $row['Type'],
							) );
							$sql = 'SELECT * FROM `samp_factions_payrank` WHERE `FactionID` = \'' . $faction . '\'';
							$resulttmp = $db->sql_query($sql);
							$row = $db->sql_fetchrow($resulttmp);
							$db->sql_freeresult($resulttmp);
							$template->assign_vars( array(
								'RANK1PAY' => $row['Rank1'],
								'RANK2PAY' => $row['Rank2'],
								'RANK3PAY' => $row['Rank3'],
								'RANK4PAY' => $row['Rank4'],
								'RANK5PAY' => $row['Rank5'],
								'RANK6PAY' => $row['Rank6'],
								'RANK7PAY' => $row['Rank7'],
								'RANK8PAY' => $row['Rank8'],
								'RANK9PAY' => $row['Rank9'],
								'RANK10PAY' => $row['Rank10']
							) );
							$sql = 'SELECT * FROM `samp_factions_weapons` WHERE `FactionID` = \'' . $faction . '\'';
							$resulttmp = $db->sql_query($sql);
							$row = $db->sql_fetchrow($resulttmp);
							$db->sql_Freeresult($resulttmp);
							$template->assign_vars( array(
								'GUN1RANK1' => $row['Gun1Rank1'], 'GUN2RANK1' => $row['Gun2Rank1'], 'GUN3RANK1' => $row['Gun3Rank1'],
								'GUN1RANK2' => $row['Gun1Rank2'], 'GUN2RANK2' => $row['Gun2Rank2'], 'GUN3RANK2' => $row['Gun3Rank2'],
								'GUN1RANK3' => $row['Gun1Rank3'], 'GUN2RANK3' => $row['Gun2Rank3'], 'GUN3RANK3' => $row['Gun3Rank3'],
								'GUN1RANK4' => $row['Gun1Rank4'], 'GUN2RANK4' => $row['Gun2Rank4'], 'GUN3RANK4' => $row['Gun3Rank4'],
								'GUN1RANK5' => $row['Gun1Rank5'], 'GUN2RANK5' => $row['Gun2Rank5'], 'GUN3RANK5' => $row['Gun3Rank5'],
								'GUN1RANK6' => $row['Gun1Rank6'], 'GUN2RANK6' => $row['Gun2Rank6'], 'GUN3RANK6' => $row['Gun3Rank6'],
								'GUN1RANK7' => $row['Gun1Rank7'], 'GUN2RANK7' => $row['Gun2Rank7'], 'GUN3RANK7' => $row['Gun3Rank7'],
								'GUN1RANK8' => $row['Gun1Rank8'], 'GUN2RANK8' => $row['Gun2Rank8'], 'GUN3RANK8' => $row['Gun3Rank8'],
								'GUN1RANK9' => $row['Gun1Rank9'], 'GUN2RANK9' => $row['Gun2Rank9'], 'GUN3RANK9' => $row['Gun3Rank9'],
								'GUN1RANK10' => $row['Gun1Rank10'], 'GUN2RANK10' => $row['Gun2Rank10'], 'GUN3RANK10' => $row['Gun3Rank10'],							
							) );	
							$sql = 'SELECT * FROM `samp_factions_weapons2` WHERE `FactionID` = \'' . $faction . '\'';
							$resulttmp = $db->sql_query($sql);
							$row = $db->sql_fetchrow($resulttmp);
							$db->sql_Freeresult($resulttmp);
							$template->assign_vars( array(
								'AMMO1RANK1' => $row['Ammo1Rank1'], 'AMMO2RANK1' => $row['Ammo2Rank1'], 'AMMO3RANK1' => $row['Ammo3Rank1'],
								'AMMO1RANK2' => $row['Ammo1Rank2'], 'AMMO2RANK2' => $row['Ammo2Rank2'], 'AMMO3RANK2' => $row['Ammo3Rank2'],
								'AMMO1RANK3' => $row['Ammo1Rank3'], 'AMMO2RANK3' => $row['Ammo2Rank3'], 'AMMO3RANK3' => $row['Ammo3Rank3'],
								'AMMO1RANK4' => $row['Ammo1Rank4'], 'AMMO2RANK4' => $row['Ammo2Rank4'], 'AMMO3RANK4' => $row['Ammo3Rank4'],
								'AMMO1RANK5' => $row['Ammo1Rank5'], 'AMMO2RANK5' => $row['Ammo2Rank5'], 'AMMO3RANK5' => $row['Ammo3Rank5'],
								'AMMO1RANK6' => $row['Ammo1Rank6'], 'AMMO2RANK6' => $row['Ammo2Rank6'], 'AMMO3RANK6' => $row['Ammo3Rank6'],
								'AMMO1RANK7' => $row['Ammo1Rank7'], 'AMMO2RANK7' => $row['Ammo2Rank7'], 'AMMO3RANK7' => $row['Ammo3Rank7'],
								'AMMO1RANK8' => $row['Ammo1Rank8'], 'AMMO2RANK8' => $row['Ammo2Rank8'], 'AMMO3RANK8' => $row['Ammo3Rank8'],
								'AMMO1RANK9' => $row['Ammo1Rank9'], 'AMMO2RANK9' => $row['Ammo2Rank9'], 'AMMO3RANK9' => $row['Ammo3Rank9'],
								'AMMO1RANK10' => $row['Ammo1Rank10'], 'AMMO2RANK10' => $row['Ammo2Rank10'], 'AMMO3RANK10' => $row['Ammo3Rank10'],
							) );	
						}
					}
				}
			}
		}
		$template->assign_vars(array(
			'L_TITLE'			=> $user->lang['UCP_SAMP_' . strtoupper($mode)],
			'VIP_890PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 1 ) ),
			'VIP_1780PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 2 ) ),
			'VIP_3560PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 3 ) ),
			'VIP_4450PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 4 ) ),
			'VIP_2314PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 5 ) ),
			'VIP_6764PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 6 ) ),
			'VIP_8900PTS' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 7 ) ),
			'URL_VIPALL' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 8 ) ),
			'URL_VIPGAR' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 9 ) ),			
			'URL_VIPOBJ' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 14 ) ),			
			'URL_VIPITEM' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 10 ) ),	
			'URL_VIPRES' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 11 ) ),	
			'URL_VIPNEOR' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "RED" ) ),		
			'URL_VIPNEOB' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "BLUE" ) ),		
			'URL_VIPNEOG' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "GREEN" ) ),		
			'URL_VIPNEOY' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "YELLOW" ) ),		
			'URL_VIPNEOP' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "PINK" ) ),		
			'URL_VIPNEOW' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "WHITE" ) ),
			'URL_VIPHALLIGHT' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "HALOGENLIGHT" ) ),
			'URL_VIPPOINTWHITE' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "POINTLIGHTWHITE" ) ),
			'URL_VIPPOINTRED' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "POINTLIGHTRED" ) ),
			'URL_VIPPOINTGREEN' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "POINTLIGHTGREEN" ) ),
			'URL_VIPPOINTBLUE' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode, 'vip' => 12, 'varColor' => "POINTLIGHTBLUE" ) ),
			'URL_CHARACTERS_CLEAN' => append_sid( "{$phpbb_root_path}ucp.$phpEx", array( 'i' => $id, 'mode' => $mode ) ),
		));
		
		
		$this->page_title = 'UCP_SAMP_' . strtoupper($mode);	
		$this->tpl_name = 'ucp_samp_' . $mode;
	}
}

?>