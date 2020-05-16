open Types.Person;
open Belt.List;

// The original talk featured the names and faces of the awesome QueerJS speakers
// and organizers.
let organizers = [
  {name: "Awesome organizer 1", image: None, twitterUserName: None},
  {name: "Awesome organizer 2", image: None, twitterUserName: None},
  {name: "Awesome organizer 3", image: None, twitterUserName: None},
];

let initialSpeakers = [
  {name: "Awesome speaker 1", image: None, twitterUserName: None},
  {name: "Awesome speaker 2", image: None, twitterUserName: None},
  {name: "Guillaume Bogard", image: None, twitterUserName: Some("@bogardguillaume")},
];

let renderPerson = (size, person) => <Person key={person.name} person size />;

[@react.component]
let make = () => {
  let (speakers, setSpeakers) = React.useState(() => initialSpeakers);
  let (isFormOpen, setIsFormOpen) = React.useState(() => false);
  
  let onNewSpeaker = speaker => setSpeakers(oldSpeakers => [speaker, ...oldSpeakers]);

  <MainWrapper>
    <h1 className="big"> "The Internet"->React.string </h1>
    <h2> "What?"->React.string </h2>
    <p>
      {React.string("This is ")}
      <i> {React.string("this")} </i>
      {React.string(" meetup! See how meta this is?")}
    </p>
    <br/>
    <h2> "Speakers"->React.string </h2>
    <Grid nbOfColumns={3}>
      {speakers->map(renderPerson(Big))->toArray->React.array}
    </Grid>
    <SpeakerForm isOpen=isFormOpen onSubmit=onNewSpeaker onToggle={isOpen => setIsFormOpen(_ => isOpen)} />
    <h2> "Organizers"->React.string </h2>
    <Grid nbOfColumns={6}>
      {organizers->map(renderPerson(Small))->toArray->React.array}
    </Grid>
  </MainWrapper>;
};