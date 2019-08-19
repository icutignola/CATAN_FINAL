#include "io.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

io::io()
{
	errorFlag = NO_ERROR_t;

	setCoordArray();
	setCoordRoadArray();


	if (al_init()) 
	{
		if (!al_install_keyboard()) {
			fprintf(stderr, "failed to initialize the keyboard!\n");
		}
		al_init_primitives_addon();
		if (al_init_image_addon())
		{
			generalInput = al_load_bitmap("InputGeneral.bmp");
			if (generalInput)
			{
				ynInput = al_load_bitmap("InputYesNo.bmp");
				if (ynInput)
				{
					tradeInput = al_load_bitmap("InputTrade.bmp");
					if (tradeInput)
					{
						showDisplay = al_create_display(WIDTH_DISPLAY, HIGH_DISPLAY);
						if (showDisplay)
						{
							colaEvAllegro = al_create_event_queue();
							if (colaEvAllegro)
							{
								if (al_install_mouse())
								{
									coordInput = al_load_bitmap("InputCoordinates.bmp");
									nameOutput = al_load_bitmap("OutputName.jpg");
									ipOutput = al_load_bitmap("OutputIp.jpg");
									waitOutput = al_load_bitmap("OutputWait.jpg");
									tryOutput = al_load_bitmap("OutputTry.jpg");
									errorOutput = al_load_bitmap("Error.jpg");
									buildingInput = al_load_bitmap("InputBuilding.bmp");
									buildingOutput = al_load_bitmap("OutputBuilding.jpg");
									TradeAcceptedOutput = al_load_bitmap("OutputIntercambioSi.jpg");
									bankTradeOutput = al_load_bitmap("OutputBankTrade.jpg");
									suprOutput = al_load_bitmap("OutputSuprRes.jpg");
									otherBankOutput = al_load_bitmap("OutputBnakOther.jpg");

									if (coordInput)
									{
										twoBmp = al_load_bitmap("two.png");
										if (twoBmp)
										{
											threeBmp = al_load_bitmap("three.png");
											if (threeBmp)
											{
												fourBmp = al_load_bitmap("four.png");
												if (fourBmp)
												{
													fiveBmp = al_load_bitmap("five.png");
													if (fiveBmp)
													{
														sixBmp = al_load_bitmap("six.png");
														if (sixBmp)
														{
															eightBmp = al_load_bitmap("eight.png");
															if (eightBmp)
															{
																nineBmp = al_load_bitmap("nine.png");
																if (nineBmp)
																{
																	tenBmp = al_load_bitmap("ten.png");
																	if (tenBmp)
																	{
																		elevenBmp = al_load_bitmap("eleven.png");
																		if (elevenBmp)
																		{
																			twelveBmp = al_load_bitmap("twelve.png");
																			if (twelveBmp)
																			{
																				woodBmp = al_load_bitmap("Wood.png");
																				if (woodBmp)
																				{
																					clayBmp = al_load_bitmap("Clay.png");
																					if (clayBmp)
																					{
																						wheatBmp = al_load_bitmap("Wheat.png");
																						if (wheatBmp)
																						{
																							stoneBmp = al_load_bitmap("Rock.png");
																							if (stoneBmp)
																							{
																								OnBmp = al_load_bitmap("TurnoOn.png");
																								if (OnBmp)
																								{
																									OffBmp = al_load_bitmap("TurnoOff.png");
																									if (OffBmp)
																									{
																										RobberBmp = al_load_bitmap("Robber.png");
																										if (RobberBmp)
																										{
																											generalOutput = al_load_bitmap("OutputGeneral.jpg");
																											if (generalOutput)
																											{
																												tradeOutput1 = al_load_bitmap("OutputTrade1.jpg");
																												if (tradeOutput1)
																												{
																													tradeOutput2 = al_load_bitmap("OutputTrade2.jpg");
																													if (tradeOutput2)
																													{
																														ynOutput = al_load_bitmap("OutputYesNo.jpg");
																														if (ynOutput)
																														{
																															errorOutput = al_load_bitmap("Error.jpg");
																															if (errorOutput)
																															{
																																sheepBmp = al_load_bitmap("Sheep.png");	
																																if (sheepBmp)
																																{
																																	seaBmp = al_load_bitmap("sea.png");
																																	if (seaBmp)
																																	{

																																		if (al_init_font_addon())
																																		{
																																			if (al_init_ttf_addon())
																																			{
																																				fuente = al_load_ttf_font("fuente.ttf", FONT_SIZE, 0);
																																				fuenteTrade = al_load_ttf_font("fuente.ttf", FONT_SIZE_TRADE, 0);
																																				fuenteName = al_load_ttf_font("fuente.ttf", FONT_SIZE_NAME, 0);
																																				printf("Allego OK");
																																				
																																				
																																			}
																																		}
																																	}
																																	else
																																	{
																																		al_destroy_bitmap(sheepBmp);
																																		al_destroy_bitmap(errorOutput);
																																		al_destroy_bitmap(ynOutput);
																																		al_destroy_bitmap(tradeOutput2);
																																		al_destroy_bitmap(tradeOutput1);
																																		al_destroy_bitmap(generalOutput);
																																		al_destroy_bitmap(RobberBmp);
																																		al_destroy_bitmap(OffBmp);
																																		al_destroy_bitmap(OnBmp);
																																		al_destroy_bitmap(wheatBmp);
																																		al_destroy_bitmap(clayBmp);
																																		al_destroy_bitmap(woodBmp);
																																		al_destroy_bitmap(twelveBmp);
																																		al_destroy_bitmap(elevenBmp);
																																		al_destroy_bitmap(tenBmp);
																																		al_destroy_bitmap(nineBmp);
																																		al_destroy_bitmap(eightBmp);
																																		al_destroy_bitmap(sevenBmp);
																																		al_destroy_bitmap(sixBmp);
																																		al_destroy_bitmap(fiveBmp);
																																		al_destroy_bitmap(fourBmp);
																																		al_destroy_bitmap(threeBmp);
																																		al_destroy_bitmap(twoBmp);
																																		al_destroy_bitmap(coordInput);
																																		al_destroy_event_queue(colaEvAllegro);
																																		al_destroy_display(showDisplay);
																																		al_destroy_bitmap(tradeInput);
																																		al_destroy_bitmap(ynInput);
																																		al_destroy_bitmap(generalInput);
																																		al_shutdown_image_addon();
																																		errInit.setErrorNumber(errInitAllegro);
																																		errorFlag = ERROR_EXIST;

																																	}
																																	
																																	
																																}
																																else
																																{
																																	al_destroy_bitmap(errorOutput);
																																	al_destroy_bitmap(ynOutput);
																																	al_destroy_bitmap(tradeOutput2);
																																	al_destroy_bitmap(tradeOutput1);
																																	al_destroy_bitmap(generalOutput);
																																	al_destroy_bitmap(RobberBmp);
																																	al_destroy_bitmap(OffBmp);
																																	al_destroy_bitmap(OnBmp);
																																	al_destroy_bitmap(wheatBmp);
																																	al_destroy_bitmap(clayBmp);
																																	al_destroy_bitmap(woodBmp);
																																	al_destroy_bitmap(twelveBmp);
																																	al_destroy_bitmap(elevenBmp);
																																	al_destroy_bitmap(tenBmp);
																																	al_destroy_bitmap(nineBmp);
																																	al_destroy_bitmap(eightBmp);
																																	al_destroy_bitmap(sevenBmp);
																																	al_destroy_bitmap(sixBmp);
																																	al_destroy_bitmap(fiveBmp);
																																	al_destroy_bitmap(fourBmp);
																																	al_destroy_bitmap(threeBmp);
																																	al_destroy_bitmap(twoBmp);
																																	al_destroy_bitmap(coordInput);
																																	al_destroy_event_queue(colaEvAllegro);
																																	al_destroy_display(showDisplay);
																																	al_destroy_bitmap(tradeInput);
																																	al_destroy_bitmap(ynInput);
																																	al_destroy_bitmap(generalInput);
																																	al_shutdown_image_addon();
																																	errInit.setErrorNumber(errInitAllegro);
																																	errorFlag = ERROR_EXIST;
																																}
																															}
																															else
																															{
																																al_destroy_bitmap(ynOutput);
																																al_destroy_bitmap(tradeOutput2);
																																al_destroy_bitmap(tradeOutput1);
																																al_destroy_bitmap(generalOutput);
																																al_destroy_bitmap(RobberBmp);
																																al_destroy_bitmap(OffBmp);
																																al_destroy_bitmap(OnBmp);
																																al_destroy_bitmap(wheatBmp);
																																al_destroy_bitmap(clayBmp);
																																al_destroy_bitmap(woodBmp);
																																al_destroy_bitmap(twelveBmp);
																																al_destroy_bitmap(elevenBmp);
																																al_destroy_bitmap(tenBmp);
																																al_destroy_bitmap(nineBmp);
																																al_destroy_bitmap(eightBmp);
																																al_destroy_bitmap(sevenBmp);
																																al_destroy_bitmap(sixBmp);
																																al_destroy_bitmap(fiveBmp);
																																al_destroy_bitmap(fourBmp);
																																al_destroy_bitmap(threeBmp);
																																al_destroy_bitmap(twoBmp);
																																al_destroy_bitmap(coordInput);
																																al_destroy_event_queue(colaEvAllegro);
																																al_destroy_display(showDisplay);
																																al_destroy_bitmap(tradeInput);
																																al_destroy_bitmap(ynInput);
																																al_destroy_bitmap(generalInput);
																																al_shutdown_image_addon();
																																errInit.setErrorNumber(errInitAllegro);
																																errorFlag = ERROR_EXIST;

																															}

																														}
																														else
																														{
																															al_destroy_bitmap(tradeOutput2);
																															al_destroy_bitmap(tradeOutput1);
																															al_destroy_bitmap(generalOutput);
																															al_destroy_bitmap(RobberBmp);
																															al_destroy_bitmap(OffBmp);
																															al_destroy_bitmap(OnBmp);
																															al_destroy_bitmap(wheatBmp);
																															al_destroy_bitmap(clayBmp);
																															al_destroy_bitmap(woodBmp);
																															al_destroy_bitmap(twelveBmp);
																															al_destroy_bitmap(elevenBmp);
																															al_destroy_bitmap(tenBmp);
																															al_destroy_bitmap(nineBmp);
																															al_destroy_bitmap(eightBmp);
																															al_destroy_bitmap(sevenBmp);
																															al_destroy_bitmap(sixBmp);
																															al_destroy_bitmap(fiveBmp);
																															al_destroy_bitmap(fourBmp);
																															al_destroy_bitmap(threeBmp);
																															al_destroy_bitmap(twoBmp);
																															al_destroy_bitmap(coordInput);
																															al_destroy_event_queue(colaEvAllegro);
																															al_destroy_display(showDisplay);
																															al_destroy_bitmap(tradeInput);
																															al_destroy_bitmap(ynInput);
																															al_destroy_bitmap(generalInput);
																															al_shutdown_image_addon();
																															errInit.setErrorNumber(errInitAllegro);
																															errorFlag = ERROR_EXIST;

																														}
																													}
																													else
																													{
																														al_destroy_bitmap(tradeOutput1);
																														al_destroy_bitmap(generalOutput);
																														al_destroy_bitmap(RobberBmp);
																														al_destroy_bitmap(OffBmp);
																														al_destroy_bitmap(OnBmp);
																														al_destroy_bitmap(wheatBmp);
																														al_destroy_bitmap(clayBmp);
																														al_destroy_bitmap(woodBmp);
																														al_destroy_bitmap(twelveBmp);
																														al_destroy_bitmap(elevenBmp);
																														al_destroy_bitmap(tenBmp);
																														al_destroy_bitmap(nineBmp);
																														al_destroy_bitmap(eightBmp);
																														al_destroy_bitmap(sevenBmp);
																														al_destroy_bitmap(sixBmp);
																														al_destroy_bitmap(fiveBmp);
																														al_destroy_bitmap(fourBmp);
																														al_destroy_bitmap(threeBmp);
																														al_destroy_bitmap(twoBmp);
																														al_destroy_bitmap(coordInput);
																														al_destroy_event_queue(colaEvAllegro);
																														al_destroy_display(showDisplay);
																														al_destroy_bitmap(tradeInput);
																														al_destroy_bitmap(ynInput);
																														al_destroy_bitmap(generalInput);
																														al_shutdown_image_addon();
																														errInit.setErrorNumber(errInitAllegro);
																														errorFlag = ERROR_EXIST;

																													}


																												}
																												else
																												{
																													al_destroy_bitmap(generalOutput);
																													al_destroy_bitmap(RobberBmp);
																													al_destroy_bitmap(OffBmp);
																													al_destroy_bitmap(OnBmp);
																													al_destroy_bitmap(wheatBmp);
																													al_destroy_bitmap(clayBmp);
																													al_destroy_bitmap(woodBmp);
																													al_destroy_bitmap(twelveBmp);
																													al_destroy_bitmap(elevenBmp);
																													al_destroy_bitmap(tenBmp);
																													al_destroy_bitmap(nineBmp);
																													al_destroy_bitmap(eightBmp);
																													al_destroy_bitmap(sevenBmp);
																													al_destroy_bitmap(sixBmp);
																													al_destroy_bitmap(fiveBmp);
																													al_destroy_bitmap(fourBmp);
																													al_destroy_bitmap(threeBmp);
																													al_destroy_bitmap(twoBmp);
																													al_destroy_bitmap(coordInput);
																													al_destroy_event_queue(colaEvAllegro);
																													al_destroy_display(showDisplay);
																													al_destroy_bitmap(tradeInput);
																													al_destroy_bitmap(ynInput);
																													al_destroy_bitmap(generalInput);
																													al_shutdown_image_addon();
																													errInit.setErrorNumber(errInitAllegro);
																													errorFlag = ERROR_EXIST;

																												}

																											}
																											else
																											{
																												al_destroy_bitmap(RobberBmp);
																												al_destroy_bitmap(OffBmp);
																												al_destroy_bitmap(OnBmp);
																												al_destroy_bitmap(wheatBmp);
																												al_destroy_bitmap(clayBmp);
																												al_destroy_bitmap(woodBmp);
																												al_destroy_bitmap(twelveBmp);
																												al_destroy_bitmap(elevenBmp);
																												al_destroy_bitmap(tenBmp);
																												al_destroy_bitmap(nineBmp);
																												al_destroy_bitmap(eightBmp);
																												al_destroy_bitmap(sevenBmp);
																												al_destroy_bitmap(sixBmp);
																												al_destroy_bitmap(fiveBmp);
																												al_destroy_bitmap(fourBmp);
																												al_destroy_bitmap(threeBmp);
																												al_destroy_bitmap(twoBmp);
																												al_destroy_bitmap(coordInput);
																												al_destroy_event_queue(colaEvAllegro);
																												al_destroy_display(showDisplay);
																												al_destroy_bitmap(tradeInput);
																												al_destroy_bitmap(ynInput);
																												al_destroy_bitmap(generalInput);
																												al_shutdown_image_addon();
																												errInit.setErrorNumber(errInitAllegro);
																												errorFlag = ERROR_EXIST;

																											}
																										}
																										else
																										{
																											al_destroy_bitmap(OffBmp);
																											al_destroy_bitmap(OnBmp);
																											al_destroy_bitmap(wheatBmp);
																											al_destroy_bitmap(clayBmp);
																											al_destroy_bitmap(woodBmp);
																											al_destroy_bitmap(twelveBmp);
																											al_destroy_bitmap(elevenBmp);
																											al_destroy_bitmap(tenBmp);
																											al_destroy_bitmap(nineBmp);
																											al_destroy_bitmap(eightBmp);
																											al_destroy_bitmap(sevenBmp);
																											al_destroy_bitmap(sixBmp);
																											al_destroy_bitmap(fiveBmp);
																											al_destroy_bitmap(fourBmp);
																											al_destroy_bitmap(threeBmp);
																											al_destroy_bitmap(twoBmp);
																											al_destroy_bitmap(coordInput);
																											al_destroy_event_queue(colaEvAllegro);
																											al_destroy_display(showDisplay);
																											al_destroy_bitmap(tradeInput);
																											al_destroy_bitmap(ynInput);
																											al_destroy_bitmap(generalInput);
																											al_shutdown_image_addon();
																											errInit.setErrorNumber(errInitAllegro);
																											errorFlag = ERROR_EXIST;

																										}
																									}
																									else
																									{
																										al_destroy_bitmap(OnBmp);
																										al_destroy_bitmap(wheatBmp);
																										al_destroy_bitmap(clayBmp);
																										al_destroy_bitmap(woodBmp);
																										al_destroy_bitmap(twelveBmp);
																										al_destroy_bitmap(elevenBmp);
																										al_destroy_bitmap(tenBmp);
																										al_destroy_bitmap(nineBmp);
																										al_destroy_bitmap(eightBmp);
																										al_destroy_bitmap(sevenBmp);
																										al_destroy_bitmap(sixBmp);
																										al_destroy_bitmap(fiveBmp);
																										al_destroy_bitmap(fourBmp);
																										al_destroy_bitmap(threeBmp);
																										al_destroy_bitmap(twoBmp);
																										al_destroy_bitmap(coordInput);
																										al_destroy_event_queue(colaEvAllegro);
																										al_destroy_display(showDisplay);
																										al_destroy_bitmap(tradeInput);
																										al_destroy_bitmap(ynInput);
																										al_destroy_bitmap(generalInput);
																										al_shutdown_image_addon();
																										errInit.setErrorNumber(errInitAllegro);
																										errorFlag = ERROR_EXIST;

																									}

																								}
																								else
																								{
																									al_destroy_bitmap(stoneBmp);
																									al_destroy_bitmap(wheatBmp);
																									al_destroy_bitmap(clayBmp);
																									al_destroy_bitmap(woodBmp);
																									al_destroy_bitmap(twelveBmp);
																									al_destroy_bitmap(elevenBmp);
																									al_destroy_bitmap(tenBmp);
																									al_destroy_bitmap(nineBmp);
																									al_destroy_bitmap(eightBmp);
																									al_destroy_bitmap(sevenBmp);
																									al_destroy_bitmap(sixBmp);
																									al_destroy_bitmap(fiveBmp);
																									al_destroy_bitmap(fourBmp);
																									al_destroy_bitmap(threeBmp);
																									al_destroy_bitmap(twoBmp);
																									al_destroy_bitmap(coordInput);
																									al_destroy_event_queue(colaEvAllegro);
																									al_destroy_display(showDisplay);
																									al_destroy_bitmap(tradeInput);
																									al_destroy_bitmap(ynInput);
																									al_destroy_bitmap(generalInput);
																									al_shutdown_image_addon();
																									errInit.setErrorNumber(errInitAllegro);
																									errorFlag = ERROR_EXIST;

																								}

																							}
																							else
																							{
																								al_destroy_bitmap(wheatBmp);
																								al_destroy_bitmap(clayBmp);
																								al_destroy_bitmap(woodBmp);
																								al_destroy_bitmap(twelveBmp);
																								al_destroy_bitmap(elevenBmp);
																								al_destroy_bitmap(tenBmp);
																								al_destroy_bitmap(nineBmp);
																								al_destroy_bitmap(eightBmp);
																								al_destroy_bitmap(sevenBmp);
																								al_destroy_bitmap(sixBmp);
																								al_destroy_bitmap(fiveBmp);
																								al_destroy_bitmap(fourBmp);
																								al_destroy_bitmap(threeBmp);
																								al_destroy_bitmap(twoBmp);
																								al_destroy_bitmap(coordInput);
																								al_destroy_event_queue(colaEvAllegro);
																								al_destroy_display(showDisplay);
																								al_destroy_bitmap(tradeInput);
																								al_destroy_bitmap(ynInput);
																								al_destroy_bitmap(generalInput);
																								al_shutdown_image_addon();
																								errInit.setErrorNumber(errInitAllegro);
																								errorFlag = ERROR_EXIST;

																							}
																						}
																						else
																						{
																							al_destroy_bitmap(clayBmp);
																							al_destroy_bitmap(woodBmp);
																							al_destroy_bitmap(twelveBmp);
																							al_destroy_bitmap(elevenBmp);
																							al_destroy_bitmap(tenBmp);
																							al_destroy_bitmap(nineBmp);
																							al_destroy_bitmap(eightBmp);
																							al_destroy_bitmap(sevenBmp);
																							al_destroy_bitmap(sixBmp);
																							al_destroy_bitmap(fiveBmp);
																							al_destroy_bitmap(fourBmp);
																							al_destroy_bitmap(threeBmp);
																							al_destroy_bitmap(twoBmp);
																							al_destroy_bitmap(coordInput);
																							al_destroy_event_queue(colaEvAllegro);
																							al_destroy_display(showDisplay);
																							al_destroy_bitmap(tradeInput);
																							al_destroy_bitmap(ynInput);
																							al_destroy_bitmap(generalInput);
																							al_shutdown_image_addon();
																							errInit.setErrorNumber(errInitAllegro);
																							errorFlag = ERROR_EXIST;

																						}
																					}
																					else
																					{
																						al_destroy_bitmap(woodBmp);
																						al_destroy_bitmap(twelveBmp);
																						al_destroy_bitmap(elevenBmp);
																						al_destroy_bitmap(tenBmp);
																						al_destroy_bitmap(nineBmp);
																						al_destroy_bitmap(eightBmp);
																						al_destroy_bitmap(sevenBmp);
																						al_destroy_bitmap(sixBmp);
																						al_destroy_bitmap(fiveBmp);
																						al_destroy_bitmap(fourBmp);
																						al_destroy_bitmap(threeBmp);
																						al_destroy_bitmap(twoBmp);
																						al_destroy_bitmap(coordInput);
																						al_destroy_event_queue(colaEvAllegro);
																						al_destroy_display(showDisplay);
																						al_destroy_bitmap(tradeInput);
																						al_destroy_bitmap(ynInput);
																						al_destroy_bitmap(generalInput);
																						al_shutdown_image_addon();
																						errInit.setErrorNumber(errInitAllegro);
																						errorFlag = ERROR_EXIST;

																					}
																				}
																				else
																				{
																				al_destroy_bitmap(twelveBmp);
																				al_destroy_bitmap(elevenBmp);
																				al_destroy_bitmap(tenBmp);
																				al_destroy_bitmap(nineBmp);
																				al_destroy_bitmap(eightBmp);
																				al_destroy_bitmap(sevenBmp);
																				al_destroy_bitmap(sixBmp);
																				al_destroy_bitmap(fiveBmp);
																				al_destroy_bitmap(fourBmp);
																				al_destroy_bitmap(threeBmp);
																				al_destroy_bitmap(twoBmp);
																				al_destroy_bitmap(coordInput);
																				al_destroy_event_queue(colaEvAllegro);
																				al_destroy_display(showDisplay);
																				al_destroy_bitmap(tradeInput);
																				al_destroy_bitmap(ynInput);
																				al_destroy_bitmap(generalInput);
																				al_shutdown_image_addon();
																				errInit.setErrorNumber(errInitAllegro);
																				errorFlag = ERROR_EXIST;

																				}

																			}
																			else
																			{
																			al_destroy_bitmap(elevenBmp);
																			al_destroy_bitmap(tenBmp);
																			al_destroy_bitmap(nineBmp);
																			al_destroy_bitmap(eightBmp);
																			al_destroy_bitmap(sevenBmp);
																			al_destroy_bitmap(sixBmp);
																			al_destroy_bitmap(fiveBmp);
																			al_destroy_bitmap(fourBmp);
																			al_destroy_bitmap(threeBmp);
																			al_destroy_bitmap(twoBmp);
																			al_destroy_bitmap(coordInput);
																			al_destroy_event_queue(colaEvAllegro);
																			al_destroy_display(showDisplay);
																			al_destroy_bitmap(tradeInput);
																			al_destroy_bitmap(ynInput);
																			al_destroy_bitmap(generalInput);
																			al_shutdown_image_addon();
																			errInit.setErrorNumber(errInitAllegro);
																			errorFlag = ERROR_EXIST;

																			}
																		}
																		else
																		{
																		al_destroy_bitmap(tenBmp);
																		al_destroy_bitmap(nineBmp);
																		al_destroy_bitmap(eightBmp);
																		al_destroy_bitmap(sevenBmp);
																		al_destroy_bitmap(sixBmp);
																		al_destroy_bitmap(fiveBmp);
																		al_destroy_bitmap(fourBmp);
																		al_destroy_bitmap(threeBmp);
																		al_destroy_bitmap(twoBmp);
																		al_destroy_bitmap(coordInput);
																		al_destroy_event_queue(colaEvAllegro);
																		al_destroy_display(showDisplay);
																		al_destroy_bitmap(tradeInput);
																		al_destroy_bitmap(ynInput);
																		al_destroy_bitmap(generalInput);
																		al_shutdown_image_addon();
																		errInit.setErrorNumber(errInitAllegro);
																		errorFlag = ERROR_EXIST;
																		}
																	}
																	else
																	{
																	al_destroy_bitmap(nineBmp);
																	al_destroy_bitmap(eightBmp);
																	al_destroy_bitmap(sixBmp);
																	al_destroy_bitmap(fiveBmp);
																	al_destroy_bitmap(fourBmp);
																	al_destroy_bitmap(threeBmp);
																	al_destroy_bitmap(twoBmp);
																	al_destroy_bitmap(coordInput);
																	al_destroy_event_queue(colaEvAllegro);
																	al_destroy_display(showDisplay);
																	al_destroy_bitmap(tradeInput);
																	al_destroy_bitmap(ynInput);
																	al_destroy_bitmap(generalInput);
																	al_shutdown_image_addon();
																	errInit.setErrorDescription("Error al inicializar mouse");
																	errInit.setErrorNumber(errInitAllegro);
																	errorFlag = ERROR_EXIST;

																	}
																}
																else
																{
																al_destroy_bitmap(eightBmp);
																al_destroy_bitmap(sixBmp);
																al_destroy_bitmap(fiveBmp);
																al_destroy_bitmap(fourBmp);
																al_destroy_bitmap(threeBmp);
																al_destroy_bitmap(twoBmp);
																al_destroy_bitmap(coordInput);
																al_destroy_event_queue(colaEvAllegro);
																al_destroy_display(showDisplay);
																al_destroy_bitmap(tradeInput);
																al_destroy_bitmap(ynInput);
																al_destroy_bitmap(generalInput);
																al_shutdown_image_addon();
																errInit.setErrorDescription("Error al inicializar mouse");
																errInit.setErrorNumber(errInitAllegro);
																errorFlag = ERROR_EXIST;

																}
															}
															else
															{
															al_destroy_bitmap(sixBmp);
															al_destroy_bitmap(fiveBmp);
															al_destroy_bitmap(fourBmp);
															al_destroy_bitmap(threeBmp);
															al_destroy_bitmap(twoBmp);
															al_destroy_bitmap(coordInput);
															al_destroy_event_queue(colaEvAllegro);
															al_destroy_display(showDisplay);
															al_destroy_bitmap(tradeInput);
															al_destroy_bitmap(ynInput);
															al_destroy_bitmap(generalInput);
															al_shutdown_image_addon();
															errInit.setErrorDescription("Error al inicializar mouse");
															errInit.setErrorNumber(errInitAllegro);
															errorFlag = ERROR_EXIST;

															}
														}
														else
														{
														al_destroy_bitmap(fiveBmp);
														al_destroy_bitmap(fourBmp);
														al_destroy_bitmap(threeBmp);
														al_destroy_bitmap(twoBmp);
														al_destroy_bitmap(coordInput);
														al_destroy_event_queue(colaEvAllegro);
														al_destroy_display(showDisplay);
														al_destroy_bitmap(tradeInput);
														al_destroy_bitmap(ynInput);
														al_destroy_bitmap(generalInput);
														al_shutdown_image_addon();
														errInit.setErrorDescription("Error al inicializar mouse");
														errInit.setErrorNumber(errInitAllegro);
														errorFlag = ERROR_EXIST;

														}
													}
													else
													{
													al_destroy_bitmap(fourBmp);
													al_destroy_bitmap(threeBmp);
													al_destroy_bitmap(twoBmp);
													al_destroy_bitmap(coordInput);
													al_destroy_event_queue(colaEvAllegro);
													al_destroy_display(showDisplay);
													al_destroy_bitmap(tradeInput);
													al_destroy_bitmap(ynInput);
													al_destroy_bitmap(generalInput);
													al_shutdown_image_addon();
													errInit.setErrorDescription("Error al inicializar mouse");
													errInit.setErrorNumber(errInitAllegro);
													errorFlag = ERROR_EXIST;

													}

												}
												else
												{
												al_destroy_bitmap(threeBmp);
												al_destroy_bitmap(twoBmp);
												al_destroy_bitmap(coordInput);
												al_destroy_event_queue(colaEvAllegro);
												al_destroy_display(showDisplay);
												al_destroy_bitmap(tradeInput);
												al_destroy_bitmap(ynInput);
												al_destroy_bitmap(generalInput);
												al_shutdown_image_addon();
												errInit.setErrorDescription("Error al inicializar mouse");
												errInit.setErrorNumber(errInitAllegro);
												errorFlag = ERROR_EXIST;

												}
											}
											else
											{
											al_destroy_bitmap(twoBmp);
											al_destroy_bitmap(coordInput);
											al_destroy_event_queue(colaEvAllegro);
											al_destroy_display(showDisplay);
											al_destroy_bitmap(tradeInput);
											al_destroy_bitmap(ynInput);
											al_destroy_bitmap(generalInput);
											al_shutdown_image_addon();
											errInit.setErrorDescription("Error al inicializar mouse");
											errInit.setErrorNumber(errInitAllegro);
											errorFlag = ERROR_EXIST;

											}
										}
										else
										{
											al_destroy_bitmap(coordInput);
											al_destroy_event_queue(colaEvAllegro);
											al_destroy_display(showDisplay);
											al_destroy_bitmap(tradeInput);
											al_destroy_bitmap(ynInput);
											al_destroy_bitmap(generalInput);
											al_shutdown_image_addon();
											errInit.setErrorDescription("Error al inicializar mouse");
											errInit.setErrorNumber(errInitAllegro);
											errorFlag = ERROR_EXIST;

										}

									}
									else
									{
										al_destroy_event_queue(colaEvAllegro);
										al_destroy_display(showDisplay);
										al_destroy_bitmap(tradeInput);
										al_destroy_bitmap(ynInput);
										al_destroy_bitmap(generalInput);
										al_shutdown_image_addon();
										errInit.setErrorDescription("Error al inicializar mouse");
										errInit.setErrorNumber(errInitAllegro);
										errorFlag = ERROR_EXIST;
									}
								}
								else
								{
									al_destroy_event_queue(colaEvAllegro);
									al_destroy_display(showDisplay);
									al_destroy_bitmap(tradeInput);
									al_destroy_bitmap(ynInput);
									al_destroy_bitmap(generalInput);
									al_shutdown_image_addon();
									errInit.setErrorDescription("Error al inicializar mouse");
									errInit.setErrorNumber(errInitAllegro);
									errorFlag = ERROR_EXIST;
								}
							}
							else
							{
								al_destroy_display(showDisplay);
								al_destroy_bitmap(tradeInput);
								al_destroy_bitmap(ynInput);
								al_destroy_bitmap(generalInput);
								al_shutdown_image_addon();
								errInit.setErrorDescription("Error al crear el display");
								errInit.setErrorNumber(errInitAllegro);
								errorFlag = ERROR_EXIST;
							}
						}
						else
						{
							al_destroy_bitmap(tradeInput);
							al_destroy_bitmap(ynInput);
							al_destroy_bitmap(generalInput);
							al_shutdown_image_addon();
							errInit.setErrorDescription("Error al crear el display");
							errInit.setErrorNumber(errInitAllegro);
							errorFlag = ERROR_EXIST;
						}

					}
					else
					{
						al_destroy_bitmap(ynInput);
						al_destroy_bitmap(generalInput);
						al_shutdown_image_addon();
						errInit.setErrorDescription("Error al cargar el bitmap tradeInput.png");
						errInit.setErrorNumber(errInitAllegro);
						errorFlag = ERROR_EXIST;
					}
				}
				else
				{
					al_destroy_bitmap(generalInput);
					al_shutdown_image_addon();
					errInit.setErrorDescription("Error al cargar el bitmap ynInput.png");
					errInit.setErrorNumber(errInitAllegro);
					errorFlag = ERROR_EXIST;
				}

			}
			else
			{
				al_shutdown_image_addon();
				errInit.setErrorDescription("Error al cargar el bitmap genInput.png");
				errInit.setErrorNumber(errInitAllegro);
				errorFlag = ERROR_EXIST;
			}

		}
		else
		{
			errInit.setErrorDescription("Error al inicializar immage_addon");
			errInit.setErrorNumber(errInitAllegro);
			errorFlag = ERROR_EXIST;
		}
	}
	else
	{
		errInit.setErrorDescription("Error al inicializar allegro general");
		errInit.setErrorNumber(errInitAllegro);
		errorFlag = ERROR_EXIST;
	}

	al_register_event_source(colaEvAllegro, al_get_display_event_source(showDisplay));
	al_register_event_source(colaEvAllegro, al_get_mouse_event_source());
	al_register_event_source(colaEvAllegro, al_get_keyboard_event_source());
}

bool io::isInput(void)
{
	bool answer = NO_EVENT	;

	if (al_get_next_event(colaEvAllegro, &evAllegro))
	{
		if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			answer = EV_EXIST;

		}
	}
	else
	{
		answer = NO_EVENT;
	}

	return answer;

}

unsigned char io::getInput(void)
{
	unsigned char answer = 0x00;


	if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (evAllegro.mouse.button & 1)
		{
			myMouse.x = evAllegro.mouse.x;
			myMouse.y = evAllegro.mouse.y;

			inputColor = al_get_pixel(generalInput, myMouse.x, myMouse.y);

			unsigned char firstC;
			unsigned char secondC;
			unsigned char thirdC;

			al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);


			if (firstC == BUTTON_A || firstC == 254)
			{
				switch (secondC)
				{
					case DICES_A:
					{
						answer = DICES_ARE;
						break;
					}
					case OFFER_A:
					{
						answer = OFFER_TRADE;
						break;
					}

					case BANK_A:
					{
						answer = BANK_TRADE;
						break;
					}

					case QUIT_A:
					{
						answer = QUIT;
						break;
					}

					case BUILD_A:
					{
						answer = BUILD;
						break;
					}

					//case PORT_A:
					//{
					//	answer = PORT_TRADE;
					//	break;
					//}
				}
			}

			else if ((firstC == NOTHING_A) && (secondC == NOTHING_A) && (thirdC == NOTHING_A))
			{
				answer = NOTHING_SELECTED;
			}


		}
		
	}

	return answer;

}

genIn io::getBuildingInput(void)
{
	genIn answer;
	answer.identifier = NO_VALUE;
	answer.x = EMPTY;
	answer.y = EMPTY;
	answer.z = EMPTY;

	bool cityF = false;
	bool casaF = false;
	bool rutaF = false;

	bool selectFlag = false;

	while (selectFlag == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(buildingInput, myMouse.x, myMouse.y);

					unsigned char firstC;
					unsigned char secondC;
					unsigned char thirdC;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if ((firstC == BUTTON_A) && (secondC == CITY_A))
					{
						if (cityF == true)
						{
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 255, 255), 6.0);
							answer.identifier = NO_VALUE;
							cityF = false;
							al_flip_display();
						}
						else
						{
							al_draw_rectangle(11, 147, 273, 147 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 215, 273, 215 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 0, 0), 6.0);
							answer.identifier = CITY;
							cityF = true;
							casaF = false;
							rutaF = false;
							al_flip_display();
						}				
					}

					else if ((firstC == BUTTON_A) && (secondC == TOWN_A))
					{
						if (casaF == true)
						{
							al_draw_rectangle(11, 147, 273, 147 + 68, al_map_rgb(255, 255, 255), 6.0);
							answer.identifier = NO_VALUE;
							casaF = false;
							al_flip_display();
						}
						else
						{
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 215, 273, 215 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 147, 273, 147 + 68, al_map_rgb(255, 0, 0), 6.0);
							answer.identifier = SETTLEMENT;
							casaF = true;
							rutaF = false;
							cityF = false;
							al_flip_display();
						}
					}

					else if ((firstC == BUTTON_A) && (secondC == ROAD_A))
					{
						if (rutaF == true)
						{
							al_draw_rectangle(11, 215, 273, 215 + 68, al_map_rgb(255, 255, 255), 6.0);
							answer.identifier = NO_VALUE;
							rutaF = false;
							al_flip_display();
						}
						else
						{
							al_draw_rectangle(11, 147, 273, 147 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 255, 255), 6.0);
							al_draw_rectangle(11, 215, 273, 215 + 68, al_map_rgb(255, 0, 0), 6.0);
							answer.identifier = ROAD;
							rutaF = true;
							casaF = false;
							cityF = false;
							al_flip_display();
						}
					}

					else if ((((firstC >= '0') && (firstC <= '5')) || ((firstC >= 'A') && (firstC <= 'S')) ||  (firstC == NO_VALUE)) && (((secondC >= '0') && (secondC <= '5')) || ((secondC >= 'A') && (secondC <= 'S')) || (secondC == NO_VALUE)) && (((thirdC >= '0') && (thirdC <= '5')) || ((thirdC >= 'A') && (thirdC <= 'S')) || (thirdC == NO_VALUE)))
					{
						if (rutaF || casaF || cityF)
						{
							answer.x = firstC;
							answer.y = secondC;
							answer.z = thirdC;
						}
					}

					else if ((firstC == BUTTON_A) && (secondC == YES_A))
					{
						selectFlag = true;
					}

					else if ((firstC == BUTTON_A) && (secondC == NO_A))
					{
						answer.identifier = NO_VALUE;
						answer.x = EMPTY;
						answer.y = EMPTY;
						answer.z = EMPTY;
						selectFlag = true;
					}

				}
			}

		}
	}


	return answer;
}

coordenates io::getCoordenates(unsigned int buildFlag)
{
	bool selectFlag = false;
	coordenates answer;

	answer.x = NOTHING_SELECTED;
	answer.y = NOTHING_SELECTED;
	answer.z = NOTHING_SELECTED;

	bool cityF;
	bool casaF;
	bool rutaF;

	if (buildFlag == CITY_A)
	{
		al_draw_rectangle(11, 78, 273, 78+68, al_map_rgb(255, 0, 0), 6.0);
		cityF = true;
	}

	else if (buildFlag == TOWN_A)
	{
		al_draw_rectangle(20, 460, 198, 460+60, al_map_rgb(255, 0, 0), 10.0);
		casaF = true;
	}

	else if (buildFlag == ROAD_A)
	{
		al_draw_rectangle(30, 530, 195, 530+60, al_map_rgb(255, 0, 0), 10.0);
		rutaF = true;
	}

	al_flip_display();

	while (selectFlag == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(buildingInput, myMouse.x, myMouse.y);

					unsigned char firstC;
					unsigned char secondC;
					unsigned char thirdC;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if ((((firstC >= '0') && (firstC <= '5')) || ((firstC >= 'A') && (firstC <= 'S'))) && (((secondC >= '0') && (secondC <= '5')) || ((secondC >= 'A') && (secondC <= 'S'))) && (((thirdC >= '0') && (thirdC <= '5')) || ((thirdC >= 'A') && (thirdC <= 'S'))))
					{
						answer.x = firstC;
						answer.y = secondC;
						answer.z = thirdC;
						
					}

					else if ((firstC == BUTTON_A) && (secondC == CITY_A))
					{
						if (cityF == true)
						{
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 255, 255), 6.0);
							cityF = false;
						}
						else
						{
							al_draw_rectangle(11, 78, 273, 78 + 68, al_map_rgb(255, 0, 0), 6.0);
							cityF = true;
						}
						
						answer.x = NOTHING_SELECTED;
						answer.y = NOTHING_SELECTED;
						answer.z = NOTHING_SELECTED;
						al_flip_display();
					}

					else if ((firstC == BUTTON_A) && (secondC == TOWN_A))
					{
						al_draw_rectangle(20, 260, 198, 260 + 60, al_map_rgb(255, 255, 255), 10.0);
						answer.x = NOTHING_SELECTED;
						answer.y = NOTHING_SELECTED;
						answer.z = NOTHING_SELECTED;
						al_flip_display();
					}

					else if ((firstC == BUTTON_A) && (secondC == ROAD_A))
					{
						al_draw_rectangle(30, 278, 195, 278 + 60, al_map_rgb(255, 255, 255), 10.0);
						answer.x = NOTHING_SELECTED;
						answer.y = NOTHING_SELECTED;
						answer.z = NOTHING_SELECTED;
						al_flip_display();
					}

					
					else if ((firstC == BUTTON_A) && (secondC == YES_A))
					{
						selectFlag = true;
						answer.x = YES;
						answer.y = YES;
						answer.z = YES;
					}

					else if ((firstC == BUTTON_A) && (secondC == NO_A))
					{
						answer.x = NOTHING_SELECTED;
						answer.y = NOTHING_SELECTED;
						answer.z = NOTHING_SELECTED;
						selectFlag = true;
					}


				}

			}

		}

	}

	return answer;
}

char io::getYN(void)
{
	bool selectFlag = false;
	char answer;

	while (selectFlag == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(ynInput, myMouse.x, myMouse.y);

					unsigned char firstC = inputColor.r;
					unsigned char secondC = inputColor.g;
					unsigned char thirdC = inputColor.b;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if( (firstC == BUTTON_A) && (secondC == YES_A))
					{
						answer = YES;
						selectFlag = true;
					}

					else if ((firstC == BUTTON_A) && (secondC == NO_A))
					{
						answer = NO;
						selectFlag = true;
					}

				}

			}

		}

	}

	return answer;

}

tradeIn io::getTradeInfo(int maxWood, int maxSheep, int maxStone, int maxClay, int maxWheat, bool pFlag)
{
	bool okSelected = false;
	tradeIn answer;

	answer.clay = 0;
	answer.wood = 0;
	answer.sheep = 0;
	answer.stone = 0;
	answer.wheat = 0;

	int contResources = 0;

	while (okSelected == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(tradeInput, myMouse.x, myMouse.y);

					unsigned char firstC = inputColor.r;
					unsigned char secondC = inputColor.g;
					unsigned char thirdC = inputColor.b;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if (firstC == BUTTON_A)
					{
						switch (secondC)
						{
							case WOOD_A:
							{
								if (contResources < 9)
								{
									answer.wood++;
									contResources++;
									if (answer.wood > maxWood)
									{
										answer.wood = maxWood;
									}
								}
								break;
							}
							case WHEAT_A:
							{
								if (contResources < 9)
								{
									answer.wheat++;
									contResources++;
									if (answer.wheat > maxWheat)
									{
										answer.wheat = maxWheat;
									}
								}
								break;
							}

							case CLAY_A:
							{
								if (contResources < 9)
								{
									answer.clay++;
									contResources++;
									if (answer.clay > maxClay)
									{
										answer.clay = maxClay;
									}
								}
								break;
							}

							case STONE_A:
							{
								if (contResources < 9)
								{
									answer.stone++;
									contResources++;
									if (answer.stone > maxStone)
									{
										answer.stone = maxStone;
									}
								}
								break;
							}

							case SHEEP_A:
							{
								if (contResources < 9)
								{
									answer.sheep++;
									contResources++;
									if (answer.sheep > maxSheep)
									{
										answer.sheep = maxSheep;
									}
								}
								break;
							}

							case OK_A:
							{
								okSelected = true;
								break;
							}

							case RESET_A:
							{
								answer.clay = 0;
								answer.wood = 0;
								answer.sheep = 0;
								answer.stone = 0;
								answer.wheat = 0;
								contResources = 0;
								break;
							}
						}
					}

					//showTrade(answer.wood, answer.sheep, answer.stone, answer.clay, answer.wheat, pFlag);
				}
					
			}

			
		}
		showTrade(answer.wood, answer.sheep, answer.stone, answer.clay, answer.wheat, pFlag);
		

	}

	return answer;
		
}

nameInfo io::getMyName(void)
{
	nameInfo answer;
	for (int j = 0; j < 255; j++)
	{
		answer.name[j] = NULL_CHAR;
	}
	bool exit = false;
	int i = 0;

	colorFont = al_map_rgb(0, 0, 0);

	while (exit == false)
	{
		if (i > 254)
		{
			exit = true;
		}
		if (al_get_next_event(colaEvAllegro, &evAllegro) && exit == false)
		{
			if (evAllegro.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (evAllegro.keyboard.keycode) 
				{
				case ALLEGRO_KEY_A:
					answer.name[i] = 'A';
					i++;
					break;

				case ALLEGRO_KEY_B:
					answer.name[i] = 'B';
					i++;
					break;

				case ALLEGRO_KEY_C:
					answer.name[i] = 'C';
					i++;
					break;

				case ALLEGRO_KEY_D:
					answer.name[i] = 'D';
					i++;
					break;

				case ALLEGRO_KEY_E:
					answer.name[i] = 'E';
					i++;
					break;

				case ALLEGRO_KEY_F:
					answer.name[i] = 'F';
					i++;
					break;

				case ALLEGRO_KEY_G:
					answer.name[i] = 'G';
					i++;
					break;

				case ALLEGRO_KEY_H:
					answer.name[i] = 'H';
					i++;
					break;

				case ALLEGRO_KEY_I:
					answer.name[i] = 'I';
					i++;
					break;

				case ALLEGRO_KEY_J:
					answer.name[i] = 'J';
					i++;
					break;

				case ALLEGRO_KEY_K:
					answer.name[i] = 'K';
					i++;
					break;

				case ALLEGRO_KEY_L:
					answer.name[i] = 'L';
					i++;
					break;

				case ALLEGRO_KEY_M:
					answer.name[i] = 'M';
					i++;
					break;

				case ALLEGRO_KEY_N:
					answer.name[i] = 'N';
					i++;
					break;

				case ALLEGRO_KEY_O:
					answer.name[i] = 'O';
					i++;
					break;

				case ALLEGRO_KEY_P:
					answer.name[i] = 'P';
					i++;
					break;

				case ALLEGRO_KEY_Q:
					answer.name[i] = 'Q';
					i++;
					break;

				case ALLEGRO_KEY_R:
					answer.name[i] = 'R';
					i++;
					break;

				case ALLEGRO_KEY_S:
					answer.name[i] = 'S';
					i++;
					break;

				case ALLEGRO_KEY_T:
					answer.name[i] = 'T';
					i++;
					break;

				case ALLEGRO_KEY_U:
					answer.name[i] = 'U';
					i++;
					break;

				case ALLEGRO_KEY_V:
					answer.name[i] = 'V';
					i++;
					break;

				case ALLEGRO_KEY_W:
					answer.name[i] = 'W';
					i++;
					break;

				case ALLEGRO_KEY_X:
					answer.name[i] = 'X';
					i++;
					break;

				case ALLEGRO_KEY_Y:
					answer.name[i] = 'Y';
					i++;
					break;
				case ALLEGRO_KEY_Z:
					answer.name[i] = 'Z';
					i++;
					break;

				case ALLEGRO_KEY_ENTER:
					exit = true;
					break;

				case ALLEGRO_KEY_BACKSPACE:
					if (i > 0)
					{
						i--;
						answer.name[i] = NULL_CHAR;
					}
					break;
				}

			}
		}

		al_draw_bitmap(nameOutput, 0, 0, 0);
		char nameAux[26];
		for (int j = 0; j < 24; j++)
		{
			nameAux[j] = answer.name[j];
		}
		if (i > 24)
		{
			nameAux[24] = '.';
			nameAux[25] = '.';
			//nameAux[26] = '.';
		}
		al_draw_text(fuenteName, colorFont, FONT_NAME_X, FONT_NAME_Y, ALLEGRO_ALIGN_LEFT, nameAux);
		al_flip_display();
	}

	answer.name[i] = NULL_CHAR;
	answer.longName = i;

	return answer;

}

char * io::getMyIp(void)
{
	char ip[15];
	for (int j = 0; j < 15; j++)
	{
		ip[j] = NULL_CHAR;
	}
	bool exit = false;
	unsigned int i = 0;

	colorFont = al_map_rgb(0, 0, 0);

	while (exit == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro) && exit == false)
		{
			if (evAllegro.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (evAllegro.keyboard.keycode)
				{
				case ALLEGRO_KEY_1:
					if (i < 15)
					{
						ip[i] = '1';
						i++;
					}
					break;

				case ALLEGRO_KEY_2:
					if (i < 15)
					{
						ip[i] = '2';
						i++;
					}
					break;

				case ALLEGRO_KEY_3:
					if (i < 15)
					{
						ip[i] = '3';
						i++;
					}
					break;

				case ALLEGRO_KEY_4:
					if (i < 15)
					{
						ip[i] = '4';
						i++;
					}
					break;

				case ALLEGRO_KEY_5:
					if (i < 15)
					{
						ip[i] = '5';
						i++;
					}
					break;

				case ALLEGRO_KEY_6:
					if (i < 15)
					{
						ip[i] = '6';
						i++;
					}
					break;

				case ALLEGRO_KEY_7:
					if (i < 15)
					{
						ip[i] = '7';
						i++;
					}
					break;

				case ALLEGRO_KEY_8:
					if (i < 15)
					{
						ip[i] = '8';
						i++;
					}
					break;

				case ALLEGRO_KEY_9:
					if (i < 15)
					{
						ip[i] = '9';
						i++;
					}
					break;

				case ALLEGRO_KEY_L:
					if (i < 15)
					{
						ip[i] = 'l';
						i++;
					}
					break;

				case ALLEGRO_KEY_O:
					if (i < 15)
					{
						ip[i] = 'o';
						i++;
					}
					break;

				case ALLEGRO_KEY_C:
					if (i < 15)
					{
						ip[i] = 'c';
						i++;
					}
					break;

				case ALLEGRO_KEY_A:
					if (i < 15)
					{
						ip[i] = 'a';
						i++;
					}
					break;

				case ALLEGRO_KEY_H:
					if (i < 15)
					{
						ip[i] = 'h';
						i++;
					}
					break;

				case ALLEGRO_KEY_S:
					if (i < 15)
					{
						ip[i] = 's';
						i++;
					}
					break;

				case ALLEGRO_KEY_T:
					if (i < 15)
					{
						ip[i] = 't';
						i++;
					}
					break;



				case ALLEGRO_KEY_0:
					if (i < 15)
					{
						ip[i] = '0';
						i++;
					}
					break;

				case ALLEGRO_KEY_FULLSTOP:
					if (i < 15)
					{
						ip[i] = '.';
						i++;
					}
					break;

				case ALLEGRO_KEY_ENTER:
					exit = true;
					break;

				case ALLEGRO_KEY_BACKSPACE:
					if (i > 0)
					{
						i--;
						ip[i] = NULL_CHAR;
					}
					break;
				}

			}
		}

		al_draw_bitmap(ipOutput, 0, 0, 0);
		al_draw_text(fuenteName, colorFont, FONT_NAME_X, FONT_NAME_Y, ALLEGRO_ALIGN_LEFT, ip);
		al_flip_display();
	}


	return ip;
}

tradeBank io::getTradeBank(void)
{
	al_draw_bitmap(bankTradeOutput,0,0,0);

	bool okSelected = false;
	bool giveFlag = false;
	bool reciveFlag = false;


	tradeBank answer;
	answer.give = NOTHING_SELECTED;
	answer.receive = NOTHING_SELECTED;

	while (okSelected == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(tradeInput, myMouse.x, myMouse.y);


					unsigned char firstC;
					unsigned char secondC;
					unsigned char thirdC;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if (firstC == BUTTON_A)
					{
						switch (secondC)
						{
							case WOOD_A:
							{
								if (giveFlag == false)
								{
									answer.give = WOOD;
									giveFlag = true;
									al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								else if (reciveFlag == false)
								{
									answer.receive = WOOD;
									reciveFlag = true;
									al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								break;
							}
							case WHEAT_A:
							{
								if (giveFlag == false)
								{
									answer.give = WHEAT;
									giveFlag = true;
									al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								else if (reciveFlag == false)
								{
									answer.receive = WHEAT;
									reciveFlag = true;
									al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);

								}
								break;
							}

							case CLAY_A:
							{
								if (giveFlag == false)
								{
									answer.give = CLAY;
									giveFlag = true;
									al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								else if (reciveFlag == false)
								{
									answer.receive = CLAY;
									reciveFlag = true;
									al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}
								break;
							}

							case STONE_A:
							{
								if (giveFlag == false)
								{
									answer.give = STONE;
									giveFlag = true;
									al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								else if (reciveFlag == false)
								{
									answer.receive = STONE;
									reciveFlag = true;
									al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}
								break;
							}

							case SHEEP_A:
							{
								if (giveFlag == false)
								{
									answer.give = SHEEP;
									giveFlag = true;
									al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}

								else if (reciveFlag == false)
								{
									answer.receive = SHEEP;
									reciveFlag = true;
									al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
								}
								break;
							}

							case OK_A:
							{
								okSelected = true;
								break;
							}

							case RESET_A:
							{
								answer.give = NOTHING_SELECTED;
								answer.receive = NOTHING_SELECTED;
								giveFlag = false;
								reciveFlag = false;
								al_draw_bitmap(bankTradeOutput, 0, 0, 0);
								break;
							}
						}
					}


				}

			}

		}

		al_flip_display();

	}

	return answer;

}

unsigned char io::getSuprResource(void)
{
	unsigned char answer = NOTHING_SELECTED;

	bool okSelected = false;

	al_draw_bitmap(suprOutput, 0, 0, 0);

	while (okSelected == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(tradeInput, myMouse.x, myMouse.y);


					unsigned char firstC;
					unsigned char secondC;
					unsigned char thirdC;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if (firstC == BUTTON_A)
					{
						switch (secondC)
						{
						case WOOD_A:
						{
							answer = WOOD;
							al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
							break;
						}
						case WHEAT_A:
						{
							answer = WHEAT;
							al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
							break;
						}

						case CLAY_A:
						{
							answer = CLAY;
							al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
							break;
						}

						case STONE_A:
						{
							answer = STONE;
							al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
							break;
						}

						case SHEEP_A:
						{
							answer = SHEEP;
							al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
							break;
						}

						case OK_A:
						{
							okSelected = true;
							break;
						}

						case RESET_A:
						{
							answer = NOTHING_SELECTED;
							al_draw_bitmap(suprOutput, 0, 0, 0);
							break;
						}
						}
					}


				}

			}

		}

		al_flip_display();

	}

	return answer;
}

//*********************************************************************************

void io::showGeneralDisplay(Player* P1, Player* P2, Map* MapIs, bool Turn, unsigned char menuType)
{
	Island *islandArray = MapIs->getIslands();

	int number;
	char position;
	int typeM;
	int j;

	al_clear_to_color(al_map_rgb(255, 255, 255));

	//FONDO
	if (menuType == GENERAL_MENU)
	{
		al_draw_bitmap(generalOutput, 0, 0, 0);
	}

	else if (menuType == BUILDING_MENU)
	{
		al_draw_bitmap(buildingOutput, 0, 0, 0);
	}

	//NOMBRE
	const char* name = P1->getName();
	colorFont = al_map_rgb(0, 0, 0);
	al_draw_text(fuenteTrade, colorFont, 800, 643, ALLEGRO_ALIGN_CENTER, name);

	//MAR
	al_draw_scaled_bitmap(seaBmp, 0, 0, al_get_bitmap_width(seaBmp), al_get_bitmap_height(seaBmp), SEA_X, SEA_Y, WIDTH_SEA, HIGH_SEA, 0);

	// MAPA
	for (int i = 0; i < ISLANDS_AMMOUNT; i++)
	{
		position = islandArray[i].getPosition();

		if (position == 'A')
		{
			for (i = 0; i <= 2; i++)
			{
				number = islandArray[i].getNumber();
				typeM = islandArray[i].getType();

				// Coloca el tipo de isla
				switch (typeM)
				{

				case BOSQUE:
				{
					al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND), FIRST_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case PASTO:
				{
					al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND), FIRST_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case MONTANIA:
				{
					al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND), FIRST_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case COLINA:
				{
					al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND) - DIFFERENCE_CLAY_X, FIRST_LINE - DIFFERENCE_CLAY_Y, WIDTH_ISLAND + DIFFERENCE_CLAY, HIGH_ISLAND + DIFFERENCE_CLAY + DIFFERENCE_CLAY, 0);
					break;
				}

				case CAMPO:
				{
					al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND), FIRST_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				}

				// Coloca el valor
				switch (number)
				{
				case 2:
				{
					al_draw_bitmap(twoBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 3:
				{
					al_draw_bitmap(threeBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 4:
				{
					al_draw_bitmap(fourBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 5:
				{
					al_draw_bitmap(fiveBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 6:
				{
					al_draw_bitmap(sixBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 8:
				{
					al_draw_bitmap(eightBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 9:
				{
					al_draw_bitmap(nineBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 10:
				{
					al_draw_bitmap(tenBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 11:
				{
					//al_draw_bitmap(elevenBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 0);
					al_draw_scaled_bitmap(elevenBmp, 0, 0, al_get_bitmap_width(elevenBmp), al_get_bitmap_height(elevenBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}

				case 12:
				{
					//al_draw_bitmap(twelveBmp, FIRST_COLUMN + (i*DISTANCE_ISLAND), FIRST_LINE, 0);
					al_draw_scaled_bitmap(twelveBmp, 0, 0, al_get_bitmap_width(twelveBmp), al_get_bitmap_height(twelveBmp), FIRST_COLUMN + (i*DISTANCE_ISLAND) + OFFSET_NUMBER, FIRST_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}
				}

			}

			i = 2;

		}

		else if (position == 'D')
		{
		j = 0;
			for (i = 3; i <= 6; i++)
			{
				number = islandArray[i].getNumber();
				typeM = islandArray[i].getType();
				
				// Coloca el tipo de isla
				switch (typeM)
				{

				case BOSQUE:
				{
					al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND), SECOND_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case PASTO:
				{
					al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND), SECOND_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case MONTANIA :
				{
					al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND), SECOND_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case COLINA:
				{
					al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND) - DIFFERENCE_CLAY_X, SECOND_LINE - DIFFERENCE_CLAY_Y, WIDTH_ISLAND +  DIFFERENCE_CLAY, HIGH_ISLAND + DIFFERENCE_CLAY + DIFFERENCE_CLAY, 0);
					break;
				}

				case CAMPO:
				{
					al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND), SECOND_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				}

				// Coloca el valor
				switch (number)
				{
				case 2:
				{
					al_draw_bitmap(twoBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 3:
				{
					al_draw_bitmap(threeBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 4:
				{
					al_draw_bitmap(fourBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 5:
				{
					al_draw_bitmap(fiveBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 6:
				{
					al_draw_bitmap(sixBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 8:
				{
					al_draw_bitmap(eightBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 9:
				{
					al_draw_bitmap(nineBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 10:
				{
					al_draw_bitmap(tenBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 11:
				{
					//al_draw_bitmap(elevenBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 0);
					al_draw_scaled_bitmap(elevenBmp, 0, 0, al_get_bitmap_width(elevenBmp), al_get_bitmap_height(elevenBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}

				case 12:
				{
					//al_draw_bitmap(twelveBmp, SECOND_COLUMN + (j*DISTANCE_ISLAND), SECOND_LINE, 0);
					al_draw_scaled_bitmap(twelveBmp, 0, 0, al_get_bitmap_width(twelveBmp), al_get_bitmap_height(twelveBmp), SECOND_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, SECOND_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}
				}
				j++;
			}

			i = 6;
		}

		else if (position == 'H')
		{
		j = 0;
			for (i = 7; i <= 11; i++)
			{
				number = islandArray[i].getNumber();
				typeM = islandArray[i].getType();

				// Coloca el tipo de isla
				switch (typeM)
				{

				case BOSQUE:
				{
					al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND), THIRD_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case PASTO:
				{
					al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND), THIRD_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case MONTANIA:
				{
					al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND), THIRD_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case COLINA:
				{
					al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND) - DIFFERENCE_CLAY_X, THIRD_LINE - DIFFERENCE_CLAY_Y, WIDTH_ISLAND + DIFFERENCE_CLAY, HIGH_ISLAND + DIFFERENCE_CLAY + DIFFERENCE_CLAY, 0);
					break;
				}

				case CAMPO:
				{
					al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND), THIRD_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				}

				// Coloca el valor
				switch (number)
				{
				case 2:
				{
					al_draw_bitmap(twoBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 3:
				{
					al_draw_bitmap(threeBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 4:
				{
					al_draw_bitmap(fourBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 5:
				{
					al_draw_bitmap(fiveBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 6:
				{
					al_draw_bitmap(sixBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 8:
				{
					al_draw_bitmap(eightBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 9:
				{
					al_draw_bitmap(nineBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 10:
				{
					al_draw_bitmap(tenBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 11:
				{
					//al_draw_bitmap(elevenBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 0);
					al_draw_scaled_bitmap(elevenBmp, 0, 0, al_get_bitmap_width(elevenBmp), al_get_bitmap_height(elevenBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}

				case 12:
				{
					//al_draw_bitmap(twelveBmp, THIRD_COLUMN + (j*DISTANCE_ISLAND), THIRD_LINE, 0);
					al_draw_scaled_bitmap(twelveBmp, 0, 0, al_get_bitmap_width(twelveBmp), al_get_bitmap_height(twelveBmp), THIRD_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, THIRD_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}
				}

				j++;
			}

			i = 11;
		}

		else if (position == 'M')
		{
		j = 0;
			for (i = 12; i <= 15; i++)
			{
				number = islandArray[i].getNumber();
				typeM = islandArray[i].getType();

				// Coloca el tipo de isla
				switch (typeM)
				{

				case BOSQUE:
				{
					al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND), FOURTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case PASTO:
				{
					al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND), FOURTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case MONTANIA:
				{
					al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND), FOURTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case COLINA:
				{
					al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND) - DIFFERENCE_CLAY_X, FOURTH_LINE - DIFFERENCE_CLAY_Y, WIDTH_ISLAND + DIFFERENCE_CLAY, HIGH_ISLAND + DIFFERENCE_CLAY + DIFFERENCE_CLAY, 0);
					break;
				}

				case CAMPO:
				{
					al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND), FOURTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				}

				// Coloca el valor
				switch (number)
				{
				case 2:
				{
					al_draw_bitmap(twoBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 3:
				{
					al_draw_bitmap(threeBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 4:
				{
					al_draw_bitmap(fourBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 5:
				{
					al_draw_bitmap(fiveBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 6:
				{
					al_draw_bitmap(sixBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 8:
				{
					al_draw_bitmap(eightBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 9:
				{
					al_draw_bitmap(nineBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 10:
				{
					al_draw_bitmap(tenBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 11:
				{
					//al_draw_bitmap(elevenBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 0);
					al_draw_scaled_bitmap(elevenBmp, 0, 0, al_get_bitmap_width(elevenBmp), al_get_bitmap_height(elevenBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}

				case 12:
				{
					//al_draw_bitmap(twelveBmp, FOURTH_COLUMN + (j*DISTANCE_ISLAND), FOURTH_LINE, 0);
					al_draw_scaled_bitmap(twelveBmp, 0, 0, al_get_bitmap_width(twelveBmp), al_get_bitmap_height(twelveBmp), FOURTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FOURTH_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}
				}
				j++;
			}

			i = 15;
		}

		else if (position == 'Q')
		{
		j = 0;
			for (i = 16; i <= 18; i++)
			{
				number = islandArray[i].getNumber();
				typeM = islandArray[i].getType();

				// Coloca el tipo de isla
				switch (typeM)
				{

				case BOSQUE:
				{
					al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND), FIFTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case PASTO:
				{
					al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND), FIFTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case MONTANIA:
				{
					al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND), FIFTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				case COLINA:
				{
					al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND) - DIFFERENCE_CLAY_X, FIFTH_LINE - DIFFERENCE_CLAY_Y, WIDTH_ISLAND + DIFFERENCE_CLAY, HIGH_ISLAND + DIFFERENCE_CLAY + DIFFERENCE_CLAY, 0);
					break;
				}

				case CAMPO:
				{
					al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND), FIFTH_LINE, WIDTH_ISLAND, HIGH_ISLAND, 0);
					break;
				}

				}

				// Coloca el valor
				switch (number)
				{
				case 2:
				{
					al_draw_bitmap(twoBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 3:
				{
					al_draw_bitmap(threeBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 4:
				{
					al_draw_bitmap(fourBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 5:
				{
					al_draw_bitmap(fiveBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 6:
				{
					al_draw_bitmap(sixBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 8:
				{
					al_draw_bitmap(eightBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 9:
				{
					al_draw_bitmap(nineBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 10:
				{
					al_draw_bitmap(tenBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					break;
				}

				case 11:
				{
					//al_draw_bitmap(elevenBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 0);
					al_draw_scaled_bitmap(elevenBmp, 0, 0, al_get_bitmap_width(elevenBmp), al_get_bitmap_height(elevenBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}

				case 12:
				{
					//al_draw_bitmap(twelveBmp, FIFTH_COLUMN + (j*DISTANCE_ISLAND), FIFTH_LINE, 0);
					al_draw_scaled_bitmap(twelveBmp, 0, 0, al_get_bitmap_width(twelveBmp), al_get_bitmap_height(twelveBmp), FIFTH_COLUMN + (j*DISTANCE_ISLAND) + OFFSET_NUMBER, FIFTH_LINE + OFFSET_NUMBER, 30, 30, 0);
					break;
				}
				}
				j++;
			}

			i = 18;
		}
	}

	// TURNO
	if (Turn == true)
	{
		al_draw_scaled_bitmap(OnBmp, 0, 0, al_get_bitmap_width(OnBmp), al_get_bitmap_height(OnBmp), TURN_X, TURN_Y, TURN_SIZE, TURN_SIZE, 0);
	}
	else
	{
		al_draw_scaled_bitmap(OffBmp, 0, 0, al_get_bitmap_width(OffBmp), al_get_bitmap_height(OffBmp), TURN_X, TURN_Y, TURN_SIZE, TURN_SIZE, 0);
	}

	//Player 1
	Coordinates* coord;
	Coordinates coordAux;
	
	int vNum, aNum;
	int x, y, z;
	char type;
	colorP1 = al_map_rgb(255, 0, 0);
	colorP2 = al_map_rgb(0, 255, 0);

	
	AbstractBuilding *buildingsArray1 = P1->getBuildings();

   	for (int i = 0; i < MAX_BUILDING_AMMOUNT; i++)
	{
		//*************************************************************************
		//Cargo las coordenadas en una variable auxiliar para luego ser comparada
		coord = buildingsArray1[i].getTokenCoordinates();
		x = coord->getX();
		y = coord->getY();
		z = coord->getZ();
		coordAux.setX(x);
		coordAux.setY(y);
		coordAux.setZ(z);
		//*************************************************************************
		//Obtengo el tipo de construccion
		type = buildingsArray1[i].getAbstractToken();
		//*************************************************************************

		vNum = getNumberV(coordAux);

		switch (vNum)
		{
			case 0:
			case 1:
			case 2:
			{
				if (type == CITY_L)
				{
					float x1 = FIRST_X_V + (vNum*DISTANCE_V);
					float y1 = FIRST_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = FIRST_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = FIRST_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 3:
			case 4:
			case 5:
			case 6:
			{
				vNum -= 3;
				if (type == CITY_L)
				{
					float x1 = SECOND_X_V + (vNum*DISTANCE_V);
					float y1 = SECOND_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = SECOND_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = SECOND_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 7:
			case 8:
			case 9:
			case 10:
			{
				vNum -= 7;
				if (type == CITY_L)
				{
					float x1 = THIRD_X_V + (vNum*DISTANCE_V);
					float y1 = THIRD_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = THIRD_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = THIRD_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			{
				vNum -= 11;
				if (type == CITY_L)
				{
					float x1 = FOURTH_X_V + (vNum*DISTANCE_V);
					float y1 = FOURTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = FOURTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = FOURTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			{
				vNum -= 16;
				if (type == CITY_L)
				{
					float x1 = FIFTH_X_V + (vNum*DISTANCE_V);
					float y1 = FIFTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = FIFTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = FIFTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;		
			}

			case 21:
			case 22:
			case 23:
			case 24:
			case 25:
			case 26:
			{
				vNum -= 21;
				if (type == CITY_L)
				{
					float x1 = SIXTH_X_V + (vNum*DISTANCE_V);
					float y1 = SIXTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = SIXTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = SIXTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 27:
			case 28:
			case 29:
			case 30:
			case 31:
			case 32:
			{
				vNum -= 27;
				if (type == CITY_L)
				{
					float x1 = SEVENTH_X_V + (vNum*DISTANCE_V);
					float y1 = SEVENTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = SEVENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = SEVENTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}
			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			{
				vNum -= 33;
				if (type == CITY_L)
				{
					float x1 = EIGTH_X_V + (vNum*DISTANCE_V);
					float y1 = EIGTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = EIGTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = EIGTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 38:
			case 39:
			case 40:
			case 41:
			case 42:
			{
				vNum -= 38;
				if (type == CITY_L)
				{
					float x1 = NINETH_X_V + (vNum*DISTANCE_V);
					float y1 = NINETH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = NINETH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = NINETH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 43:
			case 44:
			case 45:
			case 46:
			{
				vNum -= 43;
				if (type == CITY_L)
				{
					float x1 = TENTH_X_V + (vNum*DISTANCE_V);
					float y1 = TENTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = TENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = TENTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}

			case 47:
			case 48:
			case 49:
			case 50:
			{
				vNum -= 47;
				if (type == CITY_L)
				{
					float x1 = ELEVENTH_X_V + (vNum*DISTANCE_V);
					float y1 = ELEVENTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = ELEVENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = ELEVENTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}
			
			case 51:
			case 52:
			case 53:
			{
				vNum -= 51;
				if (type == CITY_L)
				{
					float x1 = TWELFTH_X_V + (vNum*DISTANCE_V);
					float y1 = TWELFTH_Y_V;
					al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP1);
				}
				else if (type == TOWN_L)
				{
					float x1 = TWELFTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
					float y1 = TWELFTH_Y_V + (SIZE_V / 2);
					al_draw_filled_circle(x1, y1, SIZE_V - 11, colorP1);
				}
				break;
			}
			
							 
		}
	}

	Road *roadsArray1 = P1->getRoads();


	for (int i = 0; i < MAX_ROAD_AMMOUNT; i++)
	{
		//*************************************************************************
		//Cargo las coordenadas en una variable auxiliar para luego ser comparada
		coord = roadsArray1[i].getTokenCoordinates();
		x = coord->getX();
		y = coord->getY();
		z = coord->getZ();
		coordAux.setX(x);
		coordAux.setY(y);
		coordAux.setZ(z);

		
		aNum = getNumberA(coordAux);

		switch (aNum)
		{
			case 0:
			case 2:
			case 4:
			{
				//imprime derecha
				float x1 = FIRST_X_A + (aNum*DISTANCE_A);
				float y1 = FIRST_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 1:
			case 3:
			case 5:
			{
				//imprime izquierda
				aNum -= 1;
				float x1 = FIRST_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
				float y1 = FIRST_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 6:
			case 7:
			case 8:
			case 9:
			{
				//imprime derecho
				aNum -= 6;
				float x1 = SECOND_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
				float y1 = SECOND_Y_A - 17;
				al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 20, colorP1, THICKNESS_LINE);
				break;
			}

			case 11:
			case 13:
			case 15:
			case 17:
			{
				//imprime derecha
				aNum -= 11;
				float x1 = THIRD_X_A + (aNum*DISTANCE_A) + 22;
				float y1 = THIRD_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 10:
			case 12:
			case 14:
			case 16:
			{
				//imprime izquierda
				aNum -= 10;
				float x1 = THIRD_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
				float y1 = THIRD_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
			{
				//imprimo derecho
				aNum -= 18;
				float x1 = FOURTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
				float y1 = FOURTH_Y_A - 17;
				al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP1, THICKNESS_LINE);
				break;
			}

			case 24:
			case 26:
			case 28:
			case 30:
			case 32:
			{
				//imprimo derecha
				aNum -= 24;
				float x1 = FIFTH_X_A + (aNum*DISTANCE_A)+30;
				float y1 = FIFTH_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 23:
			case 25:
			case 27:
			case 29:
			case 31:
			{
				//imprimo izquierda
				aNum -= 23;
				float x1 = FIFTH_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
				float y1 = FIFTH_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			case 38:
			{
				//imprimo derecho
				aNum -= 33;
				float x1 = SIXTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
				float y1 = SIXTH_Y_A - 17;
				al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP1, THICKNESS_LINE);
				break;
			}

			case 40:
			case 42:
			case 44:
			case 46:
			case 48:
			{
				//imprimo DERECHA
				aNum -= 40;
				float x1 = SEVENTH_X_A + (aNum*DISTANCE_A);
				float y1 = SEVENTH_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 39:
			case 41:
			case 43:
			case 45:
			case 47:
			{
				//imprimo IZQUIERDA
				aNum -= 39;
				float x1 = SEVENTH_X_A + (aNum*DISTANCE_A) - 20;
				float y1 = SEVENTH_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}
		
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			{
				//imprimo derecho
				aNum -= 49;
				float x1 = EIGTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A-5)-5);
				float y1 = EIGTH_Y_A - 17;
				al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP1, THICKNESS_LINE);
				break;
			}

			case 54:
			case 56:
			case 58:
			case 60:
			{
				//imprimo izquierda
				aNum -= 54;
				float x1 = NINETH_X_A + (aNum*(DISTANCE_A - 5));
				float y1 = NINETH_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}
	
			case 55:
			case 57:
			case 59:
			case 61:
			{
				//imprimo derecha
				aNum -= 55;
				float x1 = NINETH_X_A + (aNum*DISTANCE_A);
				float y1 = NINETH_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 62:
			case 63:
			case 64:
			case 65:
			{
				//imprimo derecho
				aNum -= 62;
				float x1 = TENTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
				float y1 = TENTH_Y_A - 17;
				al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP1, THICKNESS_LINE);
				break;
			}

			case 66:
			case 68:
			case 70:
			{
				//imprimo izquierda
				aNum -= 66;
				float x1 = ELEVENTH_X_A + (aNum*DISTANCE_A) - 20;
				float y1 = ELEVENTH_Y_A;
				al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}

			case 67:
			case 69:
			case 71:
			{
				//imprimo derecha 
				aNum -= 67;
				float x1 = ELEVENTH_X_A + (aNum*DISTANCE_A);
				float y1 = ELEVENTH_Y_A;
				al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP1, THICKNESS_LINE);
				break;
			}
		}
	}

	AbstractBuilding *buildingsArray2 = P2->getBuildings();

	for (int i = 0; i < MAX_BUILDING_AMMOUNT; i++)
	{
		//*************************************************************************
		//Cargo las coordenadas en una variable auxiliar para luego ser comparada
		coord = buildingsArray2[i].getTokenCoordinates();
		x = coord->getX();
		y = coord->getY();
		z = coord->getZ();
		coordAux.setX(x);
		coordAux.setY(y);
		coordAux.setZ(z);
		//*************************************************************************
		//Obtengo el tipo de construccion
		type = buildingsArray2[i].getAbstractToken();
		//*************************************************************************

		vNum = getNumberV(coordAux);

		switch (vNum)
		{
		case 0:
		case 1:
		case 2:
		{
			if (type == CITY_L)
			{
				float x1 = FIRST_X_V + (vNum*DISTANCE_V);
				float y1 = FIRST_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = FIRST_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = FIRST_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 3:
		case 4:
		case 5:
		case 6:
		{
			vNum -= 3;
			if (type == CITY_L)
			{
				float x1 = SECOND_X_V + (vNum*DISTANCE_V);
				float y1 = SECOND_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = SECOND_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = SECOND_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 7:
		case 8:
		case 9:
		case 10:
		{
			vNum -= 7;
			if (type == CITY_L)
			{
				float x1 = THIRD_X_V + (vNum*DISTANCE_V);
				float y1 = THIRD_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = THIRD_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = THIRD_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		{
			vNum -= 11;
			if (type == CITY_L)
			{
				float x1 = FOURTH_X_V + (vNum*DISTANCE_V);
				float y1 = FOURTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = FOURTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = FOURTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		{
			vNum -= 16;
			if (type == CITY_L)
			{
				float x1 = FIFTH_X_V + (vNum*DISTANCE_V);
				float y1 = FIFTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = FIFTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = FIFTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		{
			vNum -= 21;
			if (type == CITY_L)
			{
				float x1 = SIXTH_X_V + (vNum*DISTANCE_V);
				float y1 = SIXTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = SIXTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = SIXTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
		{
			vNum -= 27;
			if (type == CITY_L)
			{
				float x1 = SEVENTH_X_V + (vNum*DISTANCE_V);
				float y1 = SEVENTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = SEVENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = SEVENTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		{
			vNum -= 33;
			if (type == CITY_L)
			{
				float x1 = EIGTH_X_V + (vNum*DISTANCE_V);
				float y1 = EIGTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = EIGTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = EIGTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
		{
			vNum -= 38;
			if (type == CITY_L)
			{
				float x1 = NINETH_X_V + (vNum*DISTANCE_V);
				float y1 = NINETH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = NINETH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = NINETH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 43:
		case 44:
		case 45:
		case 46:
		{
			vNum -= 43;
			if (type == CITY_L)
			{
				float x1 = TENTH_X_V + (vNum*DISTANCE_V);
				float y1 = TENTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = TENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = TENTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 47:
		case 48:
		case 49:
		case 50:
		{
			vNum -= 47;
			if (type == CITY_L)
			{
				float x1 = ELEVENTH_X_V + (vNum*DISTANCE_V);
				float y1 = ELEVENTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = ELEVENTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = ELEVENTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}

		case 51:
		case 52:
		case 53:
		{
			vNum -= 51;
			if (type == CITY_L)
			{
				float x1 = TWELFTH_X_V + (vNum*DISTANCE_V);
				float y1 = TWELFTH_Y_V;
				al_draw_filled_rectangle(x1, y1, x1 + SIZE_V, y1 + SIZE_V, colorP2);
			}
			else if (type == TOWN_L)
			{
				float x1 = TWELFTH_X_V + (vNum*DISTANCE_V) + (SIZE_V / 2);
				float y1 = TWELFTH_Y_V + (SIZE_V / 2);
				al_draw_filled_circle(x1, y1, SIZE_V, colorP2);
			}
			break;
		}


		}
	}

	Road *roadsArray2 = P2->getRoads();

	for (int i = 0; i < MAX_ROAD_AMMOUNT; i++)
	{
		//*************************************************************************
		//Cargo las coordenadas en una variable auxiliar para luego ser comparada
		coord = roadsArray2[i].getTokenCoordinates();
		x = coord->getX();
		y = coord->getY();
		z = coord->getZ();
		coordAux.setX(x);
		coordAux.setY(y);
		coordAux.setZ(z);


		aNum = getNumberA(coordAux);

		switch (aNum)
		{
		case 0:
		case 2:
		case 4:
		{
			//imprime derecha
			float x1 = FIRST_X_A + (aNum*DISTANCE_A);
			float y1 = FIRST_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 1:
		case 3:
		case 5:
		{
			//imprime izquierda
			aNum -= 1;
			float x1 = FIRST_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
			float y1 = FIRST_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 6:
		case 7:
		case 8:
		case 9:
		{
			//imprime derecho
			aNum -= 6;
			float x1 = SECOND_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
			float y1 = SECOND_Y_A - 17;
			al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 20, colorP2, THICKNESS_LINE);
			break;
		}

		case 11:
		case 13:
		case 15:
		case 17:
		{
			//imprime derecha
			aNum -= 11;
			float x1 = THIRD_X_A + (aNum*DISTANCE_A) + 22;
			float y1 = THIRD_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 10:
		case 12:
		case 14:
		case 16:
		{
			//imprime izquierda
			aNum -= 10;
			float x1 = THIRD_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
			float y1 = THIRD_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		{
			//imprimo derecho
			aNum -= 18;
			float x1 = FOURTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
			float y1 = FOURTH_Y_A - 17;
			al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP2, THICKNESS_LINE);
			break;
		}

		case 24:
		case 26:
		case 28:
		case 30:
		case 32:
		{
			//imprimo derecha
			aNum -= 24;
			float x1 = FIFTH_X_A + (aNum*DISTANCE_A) + 30;
			float y1 = FIFTH_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 23:
		case 25:
		case 27:
		case 29:
		case 31:
		{
			//imprimo izquierda
			aNum -= 23;
			float x1 = FIFTH_X_A + (aNum*DISTANCE_A) + X_DIFFERENCE;
			float y1 = FIFTH_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 + SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		{
			//imprimo derecho
			aNum -= 33;
			float x1 = SIXTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
			float y1 = SIXTH_Y_A - 17;
			al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP2, THICKNESS_LINE);
			break;
		}

		case 40:
		case 42:
		case 44:
		case 46:
		case 48:
		{
			//imprimo DERECHA
			aNum -= 40;
			float x1 = SEVENTH_X_A + (aNum*DISTANCE_A);
			float y1 = SEVENTH_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 39:
		case 41:
		case 43:
		case 45:
		case 47:
		{
			//imprimo IZQUIERDA
			aNum -= 39;
			float x1 = SEVENTH_X_A + (aNum*DISTANCE_A) - 20;
			float y1 = SEVENTH_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		{
			//imprimo derecho
			aNum -= 49;
			float x1 = EIGTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5) - 5);
			float y1 = EIGTH_Y_A - 17;
			al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP2, THICKNESS_LINE);
			break;
		}

		case 54:
		case 56:
		case 58:
		case 60:
		{
			//imprimo izquierda
			aNum -= 54;
			float x1 = NINETH_X_A + (aNum*(DISTANCE_A - 5));
			float y1 = NINETH_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 55:
		case 57:
		case 59:
		case 61:
		{
			//imprimo derecha
			aNum -= 55;
			float x1 = NINETH_X_A + (aNum*DISTANCE_A);
			float y1 = NINETH_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 62:
		case 63:
		case 64:
		case 65:
		{
			//imprimo derecho
			aNum -= 62;
			float x1 = TENTH_X_A + (aNum*(DISTANCE_A + DISTANCE_A - 5));
			float y1 = TENTH_Y_A - 17;
			al_draw_line(x1, y1, x1, y1 + SIZE_A_Y + 23, colorP2, THICKNESS_LINE);
			break;
		}

		case 66:
		case 68:
		case 70:
		{
			//imprimo izquierda
			aNum -= 66;
			float x1 = ELEVENTH_X_A + (aNum*DISTANCE_A) - 20;
			float y1 = ELEVENTH_Y_A;
			al_draw_line(x1, y1, x1 - SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}

		case 67:
		case 69:
		case 71:
		{
			//imprimo derecha 
			aNum -= 67;
			float x1 = ELEVENTH_X_A + (aNum*DISTANCE_A);
			float y1 = ELEVENTH_Y_A;
			al_draw_line(x1, y1, x1 + SIZE_A_X, y1 - SIZE_A_Y, colorP2, THICKNESS_LINE);
			break;
		}
		}
	}

	
	//CANTIDAD DE CARTAS DE RECURSOS

	int woodCant = P1->getWood();
	int sheepCant = P1->getSheep();
	int clayCant = P1->getClay();
	int wheatCant = P1->getWheat();
	int stoneCant = P1->getStone();
	
	char buffer_aux[1];

	colorFont = al_map_rgb(0, 0, 0);

	woodCant += 0X30;
	sheepCant += 0X30;
	stoneCant += 0X30;
	clayCant += 0X30;
	wheatCant += 0X30;

	buffer_aux[0] = woodCant;
	al_draw_text(fuente, colorFont, FONT_WOOD_X, FONT_WOOD_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = sheepCant;
	al_draw_text(fuente, colorFont, FONT_SHEEP_X, FONT_SHEEP_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = clayCant;
	al_draw_text(fuente, colorFont, FONT_CLAY_X, FONT_CLAY_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = wheatCant;
	al_draw_text(fuente, colorFont, FONT_WHEAT_X, FONT_WHEAT_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = stoneCant;
	al_draw_text(fuente, colorFont, FONT_STONE_X, FONT_STONE_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	int cityCant = (MAX_CITIES - P1->getCitiesBuilt());
	int roadCant = (MAX_ROAD_AMMOUNT - P1->getRoadsBuilt());
	int townCant = (MAX_TOWNS - P1->getTownsBuilt());

	colorFont = al_map_rgb(255, 255, 255);

	cityCant += 0X30;
	roadCant += 0X30;
	townCant += 0X30;

	buffer_aux[0] = cityCant;
	al_draw_text(fuente, colorFont, FONT_CITY_X, FONT_CITY_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = roadCant;
	al_draw_text(fuente, colorFont, FONT_ROAD_X, FONT_ROAD_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = townCant;
	al_draw_text(fuente, colorFont, FONT_TOWN_X, FONT_TOWN_Y, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	al_flip_display();

}

void io::showYN(tradeIn trade1, tradeIn trade2)
{
	al_draw_bitmap(ynOutput, 0, 0, 0);

	char buffer_aux[1];

	colorFont = al_map_rgb(0, 0, 0);

	trade1.wood += 0x30;
	trade1.clay += 0x30;
	trade1.sheep += 0x30;
	trade1.stone += 0x30;
	trade1.wheat += 0x30;

	trade2.wood += 0x30;
	trade2.clay += 0x30;
	trade2.sheep += 0x30;
	trade2.stone += 0x30;
	trade2.wheat += 0x30;
	
	buffer_aux[0] = trade1.wood;
	al_draw_text(fuenteTrade, colorFont, FONT_WOOD_X_TRADE_1, FONT_WOOD_Y_TRADE_1, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade1.sheep;
	al_draw_text(fuenteTrade, colorFont, FONT_SHEEP_X_TRADE_1, FONT_SHEEP_Y_TRADE_1, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade1.clay;
	al_draw_text(fuenteTrade, colorFont, FONT_CLAY_X_TRADE_1, FONT_CLAY_Y_TRADE_1, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade1.wheat;
	al_draw_text(fuenteTrade, colorFont, FONT_WHEAT_X_TRADE_1, FONT_WHEAT_Y_TRADE_1, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade1.stone;
	al_draw_text(fuenteTrade, colorFont, FONT_STONE_X_TRADE_1, FONT_STONE_Y_TRADE_1, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade2.wood;
	al_draw_text(fuenteTrade, colorFont, FONT_WOOD_X_TRADE_2, FONT_WOOD_Y_TRADE_2, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade2.sheep;
	al_draw_text(fuenteTrade, colorFont, FONT_SHEEP_X_TRADE_2, FONT_SHEEP_Y_TRADE_2, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade2.clay;
	al_draw_text(fuenteTrade, colorFont, FONT_CLAY_X_TRADE_2, FONT_CLAY_Y_TRADE_2, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade2.wheat;
	al_draw_text(fuenteTrade, colorFont, FONT_WHEAT_X_TRADE_2, FONT_WHEAT_Y_TRADE_2, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = trade2.stone;
	al_draw_text(fuenteTrade, colorFont, FONT_STONE_X_TRADE_2, FONT_STONE_Y_TRADE_2, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	al_flip_display();
}

void io::showError(string errorDescription)
{
	al_draw_bitmap(errorOutput, 0, 0, 0);
	colorFont = al_map_rgb(0, 0, 0);
	al_draw_text(fuenteTrade, colorFont, 635, 525, ALLEGRO_ALIGN_CENTER, errorDescription.c_str());
	al_flip_display();
}

void io::showTryToConnect(void)
{
	al_draw_bitmap(tryOutput, 0, 0, 0);
	al_flip_display();
}

void io::showWaitPlayer(void)
{
	al_draw_bitmap(waitOutput, 0, 0, 0);
	al_flip_display();
}

void io::showAnswer(bool answer)
{
	if (answer == ACCEPT)
	{
		al_draw_bitmap(aceptOutput, 0, 0, 0);
	}
	else if (answer == NOT_ACCEPT)
	{
		al_draw_bitmap(notAcceptOutput, 0, 0, 0);
	}

	al_flip_display();
}

void io::showBankTradeOtherPlayer(unsigned char resP, unsigned char resB)
{
	al_draw_bitmap(otherBankOutput, 0, 0, 0);

	bool okSelected = false;

	switch (resP)
	{
	case WOOD:
	{
		al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}
	case WHEAT:
	{
		al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case CLAY:
	{
		al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case STONE:
	{
		al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case SHEEP:
	{
		al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), POS_GIVE_X, POS_GIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}
	}

	switch (resB)
	{
	case WOOD:
	{
		al_draw_scaled_bitmap(woodBmp, 0, 0, al_get_bitmap_width(woodBmp), al_get_bitmap_height(woodBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}
	case WHEAT:
	{
		al_draw_scaled_bitmap(wheatBmp, 0, 0, al_get_bitmap_width(wheatBmp), al_get_bitmap_height(wheatBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case CLAY:
	{
		al_draw_scaled_bitmap(clayBmp, 0, 0, al_get_bitmap_width(clayBmp), al_get_bitmap_height(clayBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case STONE:
	{
		al_draw_scaled_bitmap(stoneBmp, 0, 0, al_get_bitmap_width(stoneBmp), al_get_bitmap_height(stoneBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}

	case SHEEP:
	{
		al_draw_scaled_bitmap(sheepBmp, 0, 0, al_get_bitmap_width(sheepBmp), al_get_bitmap_height(sheepBmp), POS_RECIVE_X, POS_RECIVE_Y, WIDTH_ISLAND_BANK, HIGH_ISLAND_BANK, 0);
		break;
	}
	}

	al_flip_display();

	while (okSelected == false)
	{
		if (al_get_next_event(colaEvAllegro, &evAllegro))
		{
			if (evAllegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evAllegro.mouse.button & 1)
				{
					myMouse.x = evAllegro.mouse.x;
					myMouse.y = evAllegro.mouse.y;

					inputColor = al_get_pixel(tradeInput, myMouse.x, myMouse.y);


					unsigned char firstC;
					unsigned char secondC;
					unsigned char thirdC;

					al_unmap_rgb(inputColor, &firstC, &secondC, &thirdC);

					if (firstC == BUTTON_A && secondC == OK_A)
					{
						okSelected = true;
					}
				}


			}

		}

	}
}

void io::showTradeAccepted(void)
{
	al_draw_bitmap(TradeAcceptedOutput, 0, 0, 0);
	al_flip_display();
}

void io::showCantTrade(void)
{
	al_draw_bitmap(notTradeOutput, 0, 0, 0);
	al_flip_display();
}

void io::showNoResource(void)
{
	al_draw_bitmap(invalidCoordOutput, 0, 0, 0);
	al_flip_display();
}

void io::showInvalidCooord(void)
{
	al_draw_bitmap(noResourseOutput, 0, 0, 0);
	al_flip_display();
}

void io::showIWon(void)
{
	al_draw_bitmap(wonOutput, 0, 0, 0);
	al_flip_display();
}

void io::showILose(void)
{
	al_draw_bitmap(loseOutput, 0, 0, 0);
	al_flip_display();
}

void io::showTrade(int woodCant, int sheepCant, int stoneCant, int clayCant, int wheatCnat, bool Pflag)
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	
	if (Pflag == false)
	{
		al_draw_bitmap(tradeOutput1, 0, 0, 0);
	}

	else if (Pflag == true)
	{
		al_draw_bitmap(tradeOutput2, 0, 0, 0);
	}

	char buffer_aux[1];

	colorFont = al_map_rgb(0, 0, 0);

	woodCant += 0X30;
	sheepCant += 0X30;
	stoneCant += 0X30;
	clayCant += 0X30;
	wheatCnat += 0X30;

	buffer_aux[0] = woodCant;
	al_draw_text(fuenteTrade, colorFont, FONT_WOOD_X_TRADE, FONT_WOOD_Y_TRADE, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = sheepCant;
	al_draw_text(fuenteTrade, colorFont, FONT_SHEEP_X_TRADE, FONT_SHEEP_Y_TRADE, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = clayCant;
	al_draw_text(fuenteTrade, colorFont, FONT_CLAY_X_TRADE, FONT_CLAY_Y_TRADE, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = wheatCnat;
	al_draw_text(fuenteTrade, colorFont, FONT_WHEAT_X_TRADE, FONT_WHEAT_Y_TRADE, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	buffer_aux[0] = stoneCant;
	al_draw_text(fuenteTrade, colorFont, FONT_STONE_X_TRADE, FONT_STONE_Y_TRADE, ALLEGRO_ALIGN_RIGHT, buffer_aux);

	al_flip_display();

}

void io::setCoordArray(void)
{
	coordArray[0].setX('0');
	coordArray[0].setY('A');
	coordArray[0].setZ(NO_VALUE);

	coordArray[1].setX('0');
	coordArray[1].setY('B');
	coordArray[1].setZ(NO_VALUE);

	coordArray[2].setX('0');
	coordArray[2].setY('1');
	coordArray[2].setZ('C');

	coordArray[3].setX('0');
	coordArray[3].setY('5');
	coordArray[3].setZ('A');

	coordArray[4].setX('0');
	coordArray[4].setY('A');
	coordArray[4].setZ('B');

	coordArray[5].setX('0');
	coordArray[5].setY('B');
	coordArray[5].setZ('C');

	coordArray[6].setX('1');
	coordArray[6].setY('C');
	coordArray[6].setZ(NO_VALUE);

	coordArray[7].setX('5');
	coordArray[7].setY('A');
	coordArray[7].setZ('D');

	coordArray[8].setX('A');
	coordArray[8].setY('B');
	coordArray[8].setZ('E');

	coordArray[9].setX('B');
	coordArray[9].setY('C');
	coordArray[9].setZ('F');

	coordArray[10].setX('1');
	coordArray[10].setY('C');
	coordArray[10].setZ('G');

	coordArray[11].setX('5');
	coordArray[11].setY('D');
	coordArray[11].setZ(NO_VALUE);

	coordArray[12].setX('A');
	coordArray[12].setY('D');
	coordArray[12].setZ('E');

	coordArray[13].setX('B');
	coordArray[13].setY('E');
	coordArray[13].setZ('F');

	coordArray[14].setX('C');
	coordArray[14].setY('F');
	coordArray[14].setZ('G');

	coordArray[15].setX('1');
	coordArray[15].setY('G');
	coordArray[15].setZ(NO_VALUE);

	coordArray[16].setX('5');
	coordArray[16].setY('D');
	coordArray[16].setZ('H');

	coordArray[17].setX('D');
	coordArray[17].setY('E');
	coordArray[17].setZ('I');

	coordArray[18].setX('E');
	coordArray[18].setY('F');
	coordArray[18].setZ('J');

	coordArray[19].setX('F');
	coordArray[19].setY('G');
	coordArray[19].setZ('K');

	coordArray[20].setX('1');
	coordArray[20].setY('G');
	coordArray[20].setZ('L');

	coordArray[21].setX('5');
	coordArray[21].setY('H');
	coordArray[21].setZ(NO_VALUE);

	coordArray[22].setX('D');
	coordArray[22].setY('H');
	coordArray[22].setZ('I');

	coordArray[23].setX('E');
	coordArray[23].setY('I');
	coordArray[23].setZ('J');

	coordArray[24].setX('F');
	coordArray[24].setY('J');
	coordArray[24].setZ('K');

	coordArray[25].setX('G');
	coordArray[25].setY('K');
	coordArray[25].setZ('L');

	coordArray[26].setX('1');
	coordArray[26].setY('2');
	coordArray[26].setZ('L');

	coordArray[27].setX('4');
	coordArray[27].setY('5');
	coordArray[27].setZ('H');

	coordArray[28].setX('H');
	coordArray[28].setY('I');
	coordArray[28].setZ('M');

	coordArray[29].setX('I');
	coordArray[29].setY('J');
	coordArray[29].setZ('N');

	coordArray[30].setX('J');
	coordArray[30].setY('K');
	coordArray[30].setZ('O');

	coordArray[31].setX('K');
	coordArray[31].setY('L');
	coordArray[31].setZ('P');

	coordArray[32].setX('2');
	coordArray[32].setY('L');
	coordArray[32].setZ(NO_VALUE);

	coordArray[33].setX('4');
	coordArray[33].setY('H');
	coordArray[33].setZ('M');

	coordArray[34].setX('I');
	coordArray[34].setY('M');
	coordArray[34].setZ('N');

	coordArray[35].setX('J');
	coordArray[35].setY('N');
	coordArray[35].setZ('O');

	coordArray[36].setX('K');
	coordArray[36].setY('O');
	coordArray[36].setZ('P');

	coordArray[37].setX('2');
	coordArray[37].setY('L');
	coordArray[37].setZ('P');

	coordArray[38].setX('4');
	coordArray[38].setY('M');
	coordArray[38].setZ(NO_VALUE);

	coordArray[39].setX('N');
	coordArray[39].setY('M');
	coordArray[39].setZ('Q');

	coordArray[40].setX('N');
	coordArray[40].setY('O');
	coordArray[40].setZ('R');

	coordArray[41].setX('O');
	coordArray[41].setY('P');
	coordArray[41].setZ('S');

	coordArray[42].setX('2');
	coordArray[42].setY('P');
	coordArray[42].setZ(NO_VALUE);

	coordArray[43].setX('4');
	coordArray[43].setY('M');
	coordArray[43].setZ('Q');

	coordArray[44].setX('N');
	coordArray[44].setY('Q');
	coordArray[44].setZ('R');

	coordArray[45].setX('O');
	coordArray[45].setY('R');
	coordArray[45].setZ('S');

	coordArray[46].setX('2');
	coordArray[46].setY('P');
	coordArray[46].setZ('S');

	coordArray[47].setX('4');
	coordArray[47].setY('Q');
	coordArray[47].setZ(NO_VALUE);

	coordArray[48].setX('3');
	coordArray[48].setY('Q');
	coordArray[48].setZ('R');

	coordArray[49].setX('3');
	coordArray[49].setY('R');
	coordArray[49].setZ('S');

	coordArray[50].setX('2');
	coordArray[50].setY('3');
	coordArray[50].setZ('S');

	coordArray[51].setX('3');
	coordArray[51].setY('4');
	coordArray[51].setZ('Q');

	coordArray[52].setX('3');
	coordArray[52].setY('R');
	coordArray[52].setZ(NO_VALUE);

	coordArray[53].setX('3');
	coordArray[53].setY('S');
	coordArray[53].setZ(NO_VALUE);
}

void io::setCoordRoadArray(void)
{
	coordRoadArray[0].setX('0');
	coordRoadArray[0].setY('A');
	coordRoadArray[0].setZ('5');

	coordRoadArray[1].setX('0');
	coordRoadArray[1].setY('A');
	coordRoadArray[1].setZ('B');

	coordRoadArray[2].setX('0');
	coordRoadArray[2].setY('B');
	coordRoadArray[2].setZ('A');

	coordRoadArray[3].setX('0');
	coordRoadArray[3].setY('B');
	coordRoadArray[3].setZ('C');

	coordRoadArray[4].setX('0');
	coordRoadArray[4].setY('C');
	coordRoadArray[4].setZ('B');

	coordRoadArray[5].setX('1');
	coordRoadArray[5].setY('C');
	coordRoadArray[5].setZ('0');

	coordRoadArray[6].setX('5');
	coordRoadArray[6].setY('A');
	coordRoadArray[6].setZ('D');

	coordRoadArray[7].setX('A');
	coordRoadArray[7].setY('B');
	coordRoadArray[7].setZ(NO_VALUE);

	coordRoadArray[8].setX('B');
	coordRoadArray[8].setY('C');
	coordRoadArray[8].setZ(NO_VALUE);

	coordRoadArray[9].setX('1');
	coordRoadArray[9].setY('C');
	coordRoadArray[9].setZ('G');

	coordRoadArray[10].setX('5');
	coordRoadArray[10].setY('D');
	coordRoadArray[10].setZ('A');

	coordRoadArray[11].setX('A');
	coordRoadArray[11].setY('D');
	coordRoadArray[11].setZ(NO_VALUE);

	coordRoadArray[12].setX('A');
	coordRoadArray[12].setY('E');
	coordRoadArray[12].setZ(NO_VALUE);

	coordRoadArray[13].setX('B');
	coordRoadArray[13].setY('E');
	coordRoadArray[13].setZ(NO_VALUE);

	coordRoadArray[14].setX('B');
	coordRoadArray[14].setY('F');
	coordRoadArray[14].setZ(NO_VALUE);

	coordRoadArray[15].setX('C');
	coordRoadArray[15].setY('F');
	coordRoadArray[15].setZ(NO_VALUE);

	coordRoadArray[16].setX('C');
	coordRoadArray[16].setY('G');
	coordRoadArray[16].setZ(NO_VALUE);

	coordRoadArray[17].setX('1');
	coordRoadArray[17].setY('G');
	coordRoadArray[17].setZ('C');

	coordRoadArray[18].setX('5');
	coordRoadArray[18].setY('D');
	coordRoadArray[18].setZ('H');

	coordRoadArray[19].setX('D');
	coordRoadArray[19].setY('E');
	coordRoadArray[19].setZ(NO_VALUE);

	coordRoadArray[20].setX('E');
	coordRoadArray[20].setY('F');
	coordRoadArray[20].setZ(NO_VALUE);

	coordRoadArray[21].setX('F');
	coordRoadArray[21].setY('G');
	coordRoadArray[21].setZ(NO_VALUE);

	coordRoadArray[22].setX('1');
	coordRoadArray[22].setY('G');
	coordRoadArray[22].setZ('L');

	coordRoadArray[23].setX('5');
	coordRoadArray[23].setY('H');
	coordRoadArray[23].setZ('D');

	coordRoadArray[24].setX('D');
	coordRoadArray[24].setY('H');
	coordRoadArray[24].setZ(NO_VALUE);

	coordRoadArray[25].setX('D');
	coordRoadArray[25].setY('I');
	coordRoadArray[25].setZ(NO_VALUE);

	coordRoadArray[26].setX('E');
	coordRoadArray[26].setY('I');
	coordRoadArray[26].setZ(NO_VALUE);

	coordRoadArray[27].setX('E');
	coordRoadArray[27].setY('J');
	coordRoadArray[27].setZ(NO_VALUE);

	coordRoadArray[28].setX('F');
	coordRoadArray[28].setY('J');
	coordRoadArray[28].setZ(NO_VALUE);

	coordRoadArray[29].setX('F');
	coordRoadArray[29].setY('K');
	coordRoadArray[29].setZ(NO_VALUE);

	coordRoadArray[30].setX('G');
	coordRoadArray[30].setY('K');
	coordRoadArray[30].setZ(NO_VALUE);

	coordRoadArray[31].setX('G');
	coordRoadArray[31].setY('L');
	coordRoadArray[31].setZ(NO_VALUE);

	coordRoadArray[32].setX('1');
	coordRoadArray[32].setY('L');
	coordRoadArray[32].setZ('G');

	coordRoadArray[33].setX('5');
	coordRoadArray[33].setY('H');
	coordRoadArray[33].setZ('4');

	coordRoadArray[34].setX('H');
	coordRoadArray[34].setY('I');
	coordRoadArray[34].setZ(NO_VALUE);

	coordRoadArray[35].setX('I');
	coordRoadArray[35].setY('J');
	coordRoadArray[35].setZ(NO_VALUE);

	coordRoadArray[36].setX('J');
	coordRoadArray[36].setY('K');
	coordRoadArray[36].setZ(NO_VALUE);

	coordRoadArray[37].setX('K');
	coordRoadArray[37].setY('L');
	coordRoadArray[37].setZ(NO_VALUE);

	coordRoadArray[38].setX('2');
	coordRoadArray[38].setY('L');
	coordRoadArray[38].setZ('1');

	coordRoadArray[39].setX('H');
	coordRoadArray[39].setY('4');
	coordRoadArray[39].setZ('M');

	coordRoadArray[40].setX('H');
	coordRoadArray[40].setY('M');
	coordRoadArray[40].setZ(NO_VALUE);

	coordRoadArray[41].setX('I');
	coordRoadArray[41].setY('M');
	coordRoadArray[41].setZ(NO_VALUE);

	coordRoadArray[42].setX('I');
	coordRoadArray[42].setY('N');
	coordRoadArray[42].setZ(NO_VALUE);

	coordRoadArray[43].setX('J');
	coordRoadArray[43].setY('N');
	coordRoadArray[43].setZ(NO_VALUE);

	coordRoadArray[44].setX('J');
	coordRoadArray[44].setY('O');
	coordRoadArray[44].setZ(NO_VALUE);

	coordRoadArray[45].setX('K');
	coordRoadArray[45].setY('O');
	coordRoadArray[45].setZ(NO_VALUE);

	coordRoadArray[46].setX('K');
	coordRoadArray[46].setY('P');
	coordRoadArray[46].setZ(NO_VALUE);

	coordRoadArray[47].setX('L');
	coordRoadArray[47].setY('P');
	coordRoadArray[47].setZ(NO_VALUE);

	coordRoadArray[48].setX('2');
	coordRoadArray[48].setY('L');
	coordRoadArray[48].setZ('P');

	coordRoadArray[49].setX('4');
	coordRoadArray[49].setY('M');
	coordRoadArray[49].setZ('H');

	coordRoadArray[50].setX('M');
	coordRoadArray[50].setY('N');
	coordRoadArray[50].setZ(NO_VALUE);

	coordRoadArray[51].setX('N');
	coordRoadArray[51].setY('O');
	coordRoadArray[51].setZ(NO_VALUE);

	coordRoadArray[52].setX('O');
	coordRoadArray[52].setY('P');
	coordRoadArray[52].setZ(NO_VALUE);

	coordRoadArray[53].setX('2');
	coordRoadArray[53].setY('P');
	coordRoadArray[53].setZ('L');

	coordRoadArray[54].setX('4');
	coordRoadArray[54].setY('M');
	coordRoadArray[54].setZ('Q');

	coordRoadArray[55].setX('M');
	coordRoadArray[55].setY('Q');
	coordRoadArray[55].setZ(NO_VALUE);

	coordRoadArray[56].setX('N');
	coordRoadArray[56].setY('Q');
	coordRoadArray[56].setZ(NO_VALUE);

	coordRoadArray[57].setX('N');
	coordRoadArray[57].setY('R');
	coordRoadArray[57].setZ(NO_VALUE);

	coordRoadArray[58].setX('O');
	coordRoadArray[58].setY('R');
	coordRoadArray[58].setZ(NO_VALUE);

	coordRoadArray[59].setX('O');
	coordRoadArray[59].setY('S');
	coordRoadArray[59].setZ(NO_VALUE);

	coordRoadArray[60].setX('P');
	coordRoadArray[60].setY('S');
	coordRoadArray[60].setZ(NO_VALUE);

	coordRoadArray[61].setX('2');
	coordRoadArray[61].setY('P');
	coordRoadArray[61].setZ('S');

	coordRoadArray[62].setX('4');
	coordRoadArray[62].setY('Q');
	coordRoadArray[62].setZ('M');

	coordRoadArray[63].setX('Q');
	coordRoadArray[63].setY('R');
	coordRoadArray[63].setZ(NO_VALUE);

	coordRoadArray[64].setX('R');
	coordRoadArray[64].setY('S');
	coordRoadArray[64].setZ(NO_VALUE);

	coordRoadArray[65].setX('2');
	coordRoadArray[65].setY('S');
	coordRoadArray[65].setZ('3');

	coordRoadArray[66].setX('4');
	coordRoadArray[66].setY('Q');
	coordRoadArray[66].setZ('3');

	coordRoadArray[67].setX('3');
	coordRoadArray[67].setY('Q');
	coordRoadArray[67].setZ('4');

	coordRoadArray[68].setX('3');
	coordRoadArray[68].setY('R');
	coordRoadArray[68].setZ('Q');

	coordRoadArray[69].setX('3');
	coordRoadArray[69].setY('R');
	coordRoadArray[69].setZ('S');

	coordRoadArray[70].setX('3');
	coordRoadArray[70].setY('S');
	coordRoadArray[70].setZ('R');

	coordRoadArray[71].setX('3');
	coordRoadArray[71].setY('S');
	coordRoadArray[71].setZ('2');


}

int io::getNumberV(Coordinates coord)
{
	int j = 0;
	bool interrupt = false;
	do
	{
		if (coord == coordArray[j])	//Recorro el arreglo hasta que coincida con alguna coordenada o no haya mas coordenadas para comparar
		{
			interrupt = true;
		}
		else
		{
			j++;
		}
	} while ((interrupt == false) && (j < MAX_COORDENATES_AMMOUNT_V));

	return j;
}

int io::getNumberA(Coordinates coord)
{
	int j = 0;
	bool interrupt = false;
	do
	{
		if (coord == coordRoadArray[j])	//Recorro el arreglo hasta que coincida con alguna coordenada o no haya mas coordenadas para comparar
		{
			interrupt = true;
		}

		else
		{
			j++;
		}
	} while ((interrupt == false) && (j < MAX_COORDENATES_AMMOUNT_R));

	return j;
}