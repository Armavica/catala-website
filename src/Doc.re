[%bs.raw {|require("../assets/man_page.css")|}];

module type ManPage = {
  let title: string;
  let url: string;
  let html: string;
};

module MakeManPageDoc = (Man: ManPage) => {
  let url = Man.url;
  [@react.component]
  let make = () => {
    <>
      <Utils.PageTitle title=Man.title />
      <Utils.Card collapsible=false>
        <div
          className="font-mono man-page"
          dangerouslySetInnerHTML={"__html": Man.html}
        />
      </Utils.Card>
    </>;
  };
};

module CatalaManPage =
  MakeManPageDoc({
    let title = "Catala compiler documentation";
    let url = "doc/catala";
    let html: string = [%bs.raw {|require("../assets/catala.html")|}];
  });

module LegiFranceCatalaManPage =
  MakeManPageDoc({
    let title = "Catala LegiFrance connector documentation";
    let url = "doc/legifrance-catala";
    let html: string = [%bs.raw
      {|require("../assets/legifrance_catala.html")|}
    ];
  });

let url = "doc";

let catala_doc: string = [%bs.raw {|require("../assets/catala.html")|}];

let legifrance_catala_doc: string = [%bs.raw
  {|require("../assets/legifrance_catala.html")|}
];

let catala_card: Utils.presentation_card = {
  title:
    <Lang.String
      english="The Catala Compiler"
      french="Le compilateur Catala"
    />,
  action:
    Some((
      CatalaManPage.url,
      <Lang.String english="See manpage" french={js|Voir la page man|js} />,
    )),
  icon: None,
  quote: None,
  content: {
    <p>
      {React.string(
         "The compiler is the main tool that parses Catala source code files and translate
     the contents into various literate programming or executable targets.",
       )}
    </p>;
  },
};

let legifrance_catala_card: Utils.presentation_card = {
  title:
    <Lang.String
      english="The LegiFrance Catala connector"
      french={js|La connexion Catala-LégiFrance|js}
    />,
  icon: None,
  quote: None,
  action:
    Some((
      LegiFranceCatalaManPage.url,
      <Lang.String english="See manpage" french={js|Voir la page man|js} />,
    )),
  content: {
    <p>
      {React.string(
         "Only available for the French surface language, this utility connects to the LegiFrance API
     to retrieve expiration dates for the law articles used in the implementation or compare the
     text in the source code with the official legislative text.",
       )}
    </p>;
  },
};

[@react.component]
let make = () => {
  <>
    <Utils.PageTitle title="Catala tooling documentation" />
    <Utils.PresentationCards cards=[|catala_card, legifrance_catala_card|] />
  </>;
};
